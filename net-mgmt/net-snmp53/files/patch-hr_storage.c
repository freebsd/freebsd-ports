--- agent/mibgroup/host/hr_storage.c.orig	Fri Feb  8 19:42:25 2002
+++ agent/mibgroup/host/hr_storage.c	Sat Feb 16 23:37:31 2002
@@ -583,7 +583,15 @@
 			for (i = 0; i < sizeof(mbstat.m_mtypes)/sizeof(mbstat.m_mtypes[0]); i++)
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
@@ -634,7 +642,15 @@
 				+ (mclpool.pr_nget - mclpool.pr_nput)
 				    * mclpool.pr_size;
 #elif defined(MBSTAT_SYMBOL)
+#if !defined(__FreeBSD__) || __FreeBSD_version < 500021
 			long_return = mbstat.m_clusters - mbstat.m_clfree;	/* unlikely, but... */
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
