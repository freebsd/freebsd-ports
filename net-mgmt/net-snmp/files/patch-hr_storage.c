--- agent/mibgroup/host/hr_storage.c.orig	Sun Oct 17 10:59:14 2004
+++ agent/mibgroup/host/hr_storage.c	Mon Oct 25 07:49:40 2004
@@ -212,6 +212,10 @@
 void            sol_get_swapinfo(int *, int *);
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500102
+void		collect_mbuf(long *long_mbuf, long *long_mbufc);
+#endif
+
 #define	HRSTORE_MEMSIZE		1
 #define	HRSTORE_INDEX		2
 #define	HRSTORE_TYPE		3
@@ -451,7 +455,8 @@
     NULL,
     "Memory Buffers",           /* HRS_TYPE_MBUF */
     "Real Memory",              /* HRS_TYPE_MEM */
-    "Swap Space"                /* HRS_TYPE_SWAP */
+    "Swap Space",               /* HRS_TYPE_SWAP */
+    "Memory Buffer Clusters"    /* HRS_TYPE_MBUFCLUSTER */
 };
 
 
@@ -566,6 +571,7 @@
                 storage_type_id[storage_type_len - 1] = 3;      /* Virtual Mem */
                 break;
             case HRS_TYPE_MBUF:
+            case HRS_TYPE_MBUFCLUSTER:
                 storage_type_id[storage_type_len - 1] = 1;      /* Other */
                 break;
             default:
@@ -654,7 +660,7 @@
             case HRS_TYPE_SWAP:
                 long_return = memory_totals.t_vm;
                 break;
-#else               /* !linux && !solaris2 && !hpux10 && !hpux11 && ... */
+#else
             case HRS_TYPE_MEM:
                 long_return = physmem;
                 break;
@@ -664,6 +670,8 @@
 #endif
                 long_return = 0;
                 break;
+#endif              /* linux || solaris2 || hpux10 || hpux11 || ... */
+#if !defined(linux) && !defined(solaris2) && !defined(hpux10) && !defined(hpux11)
             case HRS_TYPE_MBUF:
 #if HAVE_SYS_POOL_H
                 long_return = 0;
@@ -673,7 +681,26 @@
                      i++)
                     long_return += mbstat.m_mtypes[i];
 #elif defined(MBSTAT_SYMBOL)
+#if !defined(__FreeBSD__) || __FreeBSD_version < 500021
                 long_return = mbstat.m_mbufs;
+#elif defined(__FreeBSD__) && __FreeBSD_version < 500024
+		/* mbuf stats disabled */
+		return NULL;
+#elif defined(__FreeBSD__)
+		{
+		  size_t mlen = sizeof(int);
+		  int nmbufs;
+		  if (sysctlbyname("kern.ipc.nmbufs", &nmbufs, &mlen,
+				   NULL, 0) < 0) {
+		    return NULL;
+		  }
+		  long_return = nmbufs;
+		  break;
+		}
+#else
+		/* XXX TODO: implement new method */
+		return NULL;
+#endif /* __FreeBSD__ */
 #elif defined(NO_DUMMY_VALUES)
                 goto try_next;
 #else
@@ -681,6 +708,18 @@
 #endif
                 break;
 #endif              /* !linux && !solaris2 && !hpux10 && !hpux11 && ... */
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500024
+	    case HRS_TYPE_MBUFCLUSTER: {
+	      size_t mlen = sizeof(int);
+	      int nmbclusters;
+	      if (sysctlbyname("kern.ipc.nmbclusters", &nmbclusters, &mlen,
+			       NULL, 0) < 0) {
+		return NULL;
+	      }
+	      long_return = nmbclusters;
+	      break;
+	    }
+#endif
             default:
 #if NO_DUMMY_VALUES
                 goto try_next;
@@ -733,6 +772,12 @@
                     * mclpool.pr_size;
 #elif defined(MBSTAT_SYMBOL) && defined(STRUCT_MBSTAT_HAS_M_CLUSTERS)
                 long_return = mbstat.m_clusters - mbstat.m_clfree;      /* unlikely, but... */
+#elif defined(__FreeBSD__) && __FreeBSD_version < 500102
+		/* mbuf stats disabled */
+		return NULL;
+#elif defined(__FreeBSD__)
+		collect_mbuf((long*)&long_return, (long*)NULL);
+		break;
 #elif defined(NO_DUMMY_VALUES)
                 goto try_next;
 #else
@@ -740,6 +785,11 @@
 #endif
                 break;
 #endif                      /* !linux && !solaris2 && !hpux10 && !hpux11 && ... */
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500102
+	    case HRS_TYPE_MBUFCLUSTER:
+	      collect_mbuf(NULL, &long_return);
+	      break;
+#endif
             default:
 #if NO_DUMMY_VALUES
                 goto try_next;
@@ -766,7 +816,11 @@
                 break;
 #if !defined(linux) && !defined(solaris2) && !defined(hpux10) && !defined(hpux11)  && defined(MBSTAT_SYMBOL)
             case HRS_TYPE_MBUF:
+#if defined(__FreeBSD__) && __FreeBSD_version >= 502113
+                long_return = mbstat.m_mcfail + mbstat.m_mpfail;
+#else
                 long_return = mbstat.m_drops;
+#endif
                 break;
 #endif                          /* !linux && !solaris2 && !hpux10 && !hpux11 && MBSTAT_SYMBOL */
             default:
@@ -892,3 +946,97 @@
     *usedP = ainfo.ani_resv;
 }
 #endif                          /* solaris2 */
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500102
+void
+collect_mbuf(long *long_mbuf, long *long_mbufc)
+{
+#if __FreeBSD_version >= 502113
+  size_t mlen;
+  struct mbstat mbstat;
+
+  mlen = sizeof mbstat;
+  if (sysctlbyname("kern.ipc.mbstat", &mbstat, &mlen, NULL, 0) < 0) {
+    warn("sysctl: retrieving mbstat");
+    return;
+  }
+  if (mbstat.m_mbufs < 0) mbstat.m_mbufs = 0;		/* XXX */
+  if (mbstat.m_mclusts < 0) mbstat.m_mclusts = 0;	/* XXX */
+  if (long_mbuf) {
+    *long_mbuf = mbstat.m_mbufs;
+  }
+  if (long_mbufc) {
+    *long_mbufc = mbstat.m_mclusts;
+  }
+#else
+  int i, j, num_objs;
+  size_t mlen;
+  u_long totused[2];
+  u_long totnum, totfree;
+  struct mbstat mbstat;
+  struct mbpstat **mbpstat = NULL;
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
+
+  for (i = 0; i < num_objs; i++)
+    mbpstat[i] = mbpstat[0] + i;
+
+#define	GENLST		(num_objs - 1)
+
+  totnum = mbpstat[GENLST]->mb_mbbucks * mbstat.m_mbperbuck;
+  totfree = mbpstat[GENLST]->mb_mbfree;
+  for (i = 0; i < (num_objs - 1); i++) {
+    if (mbpstat[i]->mb_active == 0)
+      continue;
+    totnum += mbpstat[i]->mb_mbbucks * mbstat.m_mbperbuck;
+    totfree += mbpstat[i]->mb_mbfree;
+  }
+  totused[0] = totnum - totfree;
+  totnum = mbpstat[GENLST]->mb_clbucks * mbstat.m_clperbuck;
+  totfree = mbpstat[GENLST]->mb_clfree;
+  for (i = 0; i < (num_objs - 1); i++) {
+    if (mbpstat[i]->mb_active == 0)
+      continue;
+    totnum += mbpstat[i]->mb_clbucks * mbstat.m_clperbuck;
+    totfree += mbpstat[i]->mb_clfree;
+  }
+  totused[1] = totnum - totfree;
+
+  if (long_mbuf) {
+    *long_mbuf = totused[0];
+  }
+  if (long_mbufc) {
+    *long_mbufc = totused[1];
+  }
+
+ err:
+  if (mbpstat != NULL) {
+    if (mbpstat[0] != NULL)
+      free(mbpstat[0]);
+    free(mbpstat);
+  }
+#endif
+}
+#endif
