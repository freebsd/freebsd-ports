--- agent/mibgroup/host/hr_storage.c.orig	Thu Jan 29 22:53:59 2004
+++ agent/mibgroup/host/hr_storage.c	Tue May  4 17:06:38 2004
@@ -148,7 +148,7 @@
 #define HRFS_mount	mnt_mountp
 #define HRFS_statfs	statvfs
 
-#elif defined(HAVE_STATVFS)
+#elif defined(HAVE_STATVFS) && defined(HAVE_MNTENT)
 
 extern struct mntent *HRFS_entry;
 extern int      fscount;
@@ -193,6 +193,10 @@
 void            sol_get_swapinfo(int *, int *);
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500024
+void		collect_mbuf(long *long_mbuf, long *long_mbuf_max);
+#endif
+
 #define	HRSTORE_MEMSIZE		1
 #define	HRSTORE_INDEX		2
 #define	HRSTORE_TYPE		3
@@ -567,7 +571,7 @@
         }
     case HRSTORE_UNITS:
         if (store_idx > HRS_TYPE_FIXED_MAX)
-#if STRUCT_STATVFS_HAS_F_FRSIZE
+#if defined(STRUCT_STATVFS_HAS_F_FRSIZE) && defined(HAVE_MNTENT)
             long_return = stat_buf.f_frsize;
 #else
             long_return = stat_buf.f_bsize;
@@ -631,7 +635,7 @@
             case HRS_TYPE_SWAP:
                 long_return = memory_totals.t_vm;
                 break;
-#else               /* !linux && !solaris2 && !hpux10 && !hpux11 && ... */
+#else
             case HRS_TYPE_MEM:
                 long_return = physmem;
                 break;
@@ -641,6 +645,8 @@
 #endif
                 long_return = 0;
                 break;
+#endif              /* linux || solaris2 || hpux10 || hpux11 || ... */
+#if !defined(linux) && !defined(solaris2) && !defined(hpux10) && !defined(hpux11)
             case HRS_TYPE_MBUF:
 #if HAVE_SYS_POOL_H
                 long_return = 0;
@@ -650,7 +656,18 @@
                      i++)
                     long_return += mbstat.m_mtypes[i];
 #elif defined(MBSTAT_SYMBOL)
+#if !defined(__FreeBSD__) || __FreeBSD_version < 500021
                 long_return = mbstat.m_mbufs;
+#elif defined(__FreeBSD__) && __FreeBSD_version < 500024
+			/* mbuf stats disabled */
+			return NULL;
+#elif defined(__FreeBSD__)
+			collect_mbuf((long*)NULL, (long*)&long_return);
+			break;
+#else
+			/* XXX TODO: implement new method */
+			return NULL;
+#endif /* __FreeBSD__ */
 #elif defined(NO_DUMMY_VALUES)
                 goto try_next;
 #else
@@ -708,7 +725,18 @@
                     * mbpool.pr_size + (mclpool.pr_nget - mclpool.pr_nput)
                     * mclpool.pr_size;
 #elif defined(MBSTAT_SYMBOL)
+#if !defined(__FreeBSD__) || __FreeBSD_version < 500021
                 long_return = mbstat.m_clusters - mbstat.m_clfree;      /* unlikely, but... */
+#elif defined(__FreeBSD__) && __FreeBSD_version < 500024
+			/* mbuf stats disabled */
+			return NULL;
+#elif defined(__FreeBSD__)
+			collect_mbuf((long*)&long_return, (long*)NULL);
+			break;
+#else
+			/* XXX not supported. */
+			return NULL;
+#endif
 #elif defined(NO_DUMMY_VALUES)
                 goto try_next;
 #else
@@ -853,3 +881,132 @@
     *usedP = ainfo.ani_resv;
 }
 #endif                          /* solaris2 */
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500024
+void
+collect_mbuf(long *long_mbuf, long *long_mbuf_max)
+{
+  int i, j, nmbufs, nmbclusters, page_size, num_objs;
+  short nmbtypes;
+  size_t mlen;
+  long *mbtypes = NULL;
+  u_int mbuf_hiwm, clust_hiwm, mbuf_lowm, clust_lowm;
+  u_long totspace[2], totused[2];
+  u_long totnum, totfree;
+  struct mbstat mbstat;
+  struct mbpstat **mbpstat = NULL;
+  int *seen = NULL;
+
+  if (sysctlbyname("kern.ipc.mb_statpcpu", NULL, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving mb_statpcpu len");
+    goto err;
+  } 
+  num_objs = (int)(mlen / sizeof(struct mbpstat));
+  if ((mbpstat = calloc(num_objs, sizeof(struct mbpstat *))) == NULL) {
+    warn("calloc: cannot allocate memory for mbpstats pointers");
+    goto err;
+  }
+  if ((mbpstat[0] = calloc(num_objs, sizeof(struct mbpstat))) == NULL) {
+    warn("calloc: cannot allocate memory for mbpstats");
+    goto err;
+  }
+
+  if (sysctlbyname("kern.ipc.mb_statpcpu", mbpstat[0], &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving mb_statpcpu");
+    goto err;
+  }
+  mlen = sizeof mbstat;
+  if (sysctlbyname("kern.ipc.mbstat", &mbstat, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving mbstat");
+    goto err;
+  }
+  mlen = sizeof(int);
+  if (sysctlbyname("kern.ipc.nmbclusters", &nmbclusters, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving nmbclusters");
+    goto err;
+  }
+  mlen = sizeof(int);
+  if (sysctlbyname("kern.ipc.nmbufs", &nmbufs, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving nmbufs");
+    goto err;
+  }
+  mlen = sizeof(u_int);
+  if (sysctlbyname("kern.ipc.mbuf_hiwm", &mbuf_hiwm, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving mbuf_hiwm");
+    goto err;
+  }
+  mlen = sizeof(u_int);
+  if (sysctlbyname("kern.ipc.clust_hiwm", &clust_hiwm, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving clust_hiwm");
+    goto err;
+  }
+  mlen = sizeof(u_int);
+  if (sysctlbyname("kern.ipc.mbuf_lowm", &mbuf_lowm, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving mbuf_lowm");
+    goto err;
+  }
+  mlen = sizeof(u_int);
+  if (sysctlbyname("kern.ipc.clust_lowm", &clust_lowm, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving clust_lowm");
+    goto err;
+  }
+  mlen = sizeof(int);
+  if (sysctlbyname("hw.pagesize", &page_size, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving hw.pagesize");
+    goto err;
+  }
+
+  nmbtypes = mbstat.m_numtypes;
+  if ((seen = calloc(nmbtypes, sizeof(*seen))) == NULL) {
+    warn("calloc: cannot allocate memory for mbtypes seen flag");
+    goto err;
+  }
+  if ((mbtypes = calloc(nmbtypes, sizeof(long *))) == NULL) { 
+    warn("calloc: cannot allocate memory for mbtypes");
+    goto err;
+  }
+
+  for (i = 0; i < num_objs; i++)
+    mbpstat[i] = mbpstat[0] + i;
+
+#undef MSIZE
+#define MSIZE		(mbstat.m_msize)
+#undef MCLBYTES
+#define	MCLBYTES	(mbstat.m_mclbytes)
+#define	GENLST		(num_objs - 1)
+
+  totnum = mbpstat[GENLST]->mb_mbbucks * mbstat.m_mbperbuck;
+  totfree = mbpstat[GENLST]->mb_mbfree;
+  for (j = 1; j < nmbtypes; j++)
+    mbtypes[j] += mbpstat[GENLST]->mb_mbtypes[j];
+  totspace[0] = mbpstat[GENLST]->mb_mbbucks * mbstat.m_mbperbuck * MSIZE;
+  for (i = 0; i < (num_objs - 1); i++) {
+    if (mbpstat[i]->mb_active == 0)
+      continue;
+    totspace[0] += mbpstat[i]->mb_mbbucks*mbstat.m_mbperbuck*MSIZE;
+    totnum += mbpstat[i]->mb_mbbucks * mbstat.m_mbperbuck;
+    totfree += mbpstat[i]->mb_mbfree;
+    for (j = 1; j < nmbtypes; j++)
+      mbtypes[j] += mbpstat[i]->mb_mbtypes[j]; 
+  }
+  totused[0] = totnum - totfree;
+
+  if (long_mbuf) {
+    *long_mbuf = totused[0];
+  }
+  if (long_mbuf_max) {
+    *long_mbuf_max = nmbufs;
+  }
+
+ err:
+  if (mbtypes != NULL)
+    free(mbtypes);
+  if (seen != NULL)
+    free(seen);
+  if (mbpstat != NULL) {
+    if (mbpstat[0] != NULL)
+      free(mbpstat[0]);
+    free(mbpstat);
+  }
+}
+#endif
