--- agent/mibgroup/host/hr_storage.c.orig	Sat Apr 20 16:30:03 2002
+++ agent/mibgroup/host/hr_storage.c	Wed Apr 24 01:37:29 2002
@@ -604,7 +604,15 @@
                      i++)
                     long_return += mbstat.m_mtypes[i];
 #elif defined(MBSTAT_SYMBOL)
+#if !defined(__FreeBSD__) || __FreeBSD_version < 500021
                 long_return = mbstat.m_mbufs;
+#elif __FreeBSD_version < 500024
+			/* mbuf stats disabled */
+			return NULL;
+#else
+			/* XXX TODO: implement new method */
+			return NULL;
+#endif
 #elif defined(NO_DUMMY_VALUES)
                 return NULL;
 #else
@@ -654,7 +662,15 @@
                     * mbpool.pr_size + (mclpool.pr_nget - mclpool.pr_nput)
                     * mclpool.pr_size;
 #elif defined(MBSTAT_SYMBOL)
+#if !defined(__FreeBSD__) || __FreeBSD_version < 500021
                 long_return = mbstat.m_clusters - mbstat.m_clfree;      /* unlikely, but... */
+#elif __FreeBSD_version < 500024
+			/* mbuf stats disabled */
+			return NULL;
+#else
+			/* XXX TODO: implement new method */
+			return NULL;
+#endif
 #elif defined(NO_DUMMY_VALUES)
                 return NULL;
 #else
