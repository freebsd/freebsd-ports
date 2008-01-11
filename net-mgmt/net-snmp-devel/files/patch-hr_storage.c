--- agent/mibgroup/host/hr_storage.c.orig	2007-06-08 19:33:58.000000000 +0900
+++ agent/mibgroup/host/hr_storage.c	2008-01-11 21:37:48.767962726 +0900
@@ -229,7 +229,7 @@
 mach_port_t myHost;
 #endif
 
-static int      physmem, pagesize;
+static u_long      physmem, pagesize;
 static void parse_storage_config(const char *, char *);
 
         /*********************
@@ -252,6 +252,10 @@
 void            sol_get_swapinfo(int *, int *);
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500102
+void		collect_mbuf(long *long_mbuf, long *long_mbufc);
+#endif
+
 #define	HRSTORE_MEMSIZE		1
 #define	HRSTORE_INDEX		2
 #define	HRSTORE_TYPE		3
@@ -499,7 +503,8 @@
     NULL,
     "Memory Buffers",           /* HRS_TYPE_MBUF */
     "Real Memory",              /* HRS_TYPE_MEM */
-    "Swap Space"                /* HRS_TYPE_SWAP */
+    "Swap Space",               /* HRS_TYPE_SWAP */
+    "Memory Buffer Clusters"    /* HRS_TYPE_MBUFCLUSTER */
 };
 
 
@@ -647,6 +652,7 @@
                 storage_type_id[storage_type_len - 1] = 3;      /* Virtual Mem */
                 break;
             case HRS_TYPE_MBUF:
+            case HRS_TYPE_MBUFCLUSTER:
                 storage_type_id[storage_type_len - 1] = 1;      /* Other */
                 break;
             default:
@@ -752,7 +758,7 @@
                 long_return = memory_totals.t_vm;
 #endif
                 break;
-#else               /* !linux && !solaris2 && !hpux10 && !hpux11 && ... */
+#else
             case HRS_TYPE_MEM:
                 long_return = physmem;
                 break;
@@ -774,13 +780,45 @@
                      i++)
                     long_return += mbstat.m_mtypes[i];
 #elif defined(MBSTAT_SYMBOL) && defined(STRUCT_MBSTAT_HAS_M_MBUFS)
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
+#error "XXX"
+		/* XXX TODO: implement new method */
+		return NULL;
+#endif /* __FreeBSD__ */
 #elif defined(NO_DUMMY_VALUES)
                 goto try_next;
 #else
                 long_return = 0;
 #endif
                 break;
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
@@ -856,6 +894,12 @@
 #endif
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
@@ -863,6 +907,11 @@
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
@@ -889,7 +938,11 @@
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
@@ -1015,6 +1068,100 @@
 }
 #endif                          /* solaris2 */
 
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
+
 #ifdef WIN32
 char *win_realpath(const char *file_name, char *resolved_name)
 {
