--- agent/mibgroup/host/hr_storage.c.orig	Thu Mar 22 14:27:21 2001
+++ agent/mibgroup/host/hr_storage.c	Thu Oct 11 12:19:18 2001
@@ -523,8 +523,18 @@
 			for (i = 0; i < sizeof(mbstat.m_mtypes)/sizeof(mbstat.m_mtypes[0]); i++)
 			    long_return += mbstat.m_mtypes[i];
 #elif defined(MBSTAT_SYMBOL)
+#if __FreeBSD_version < 500021
 			long_return = mbstat.m_mbufs;
 #else
+#if __FreeBSD_version < 500024
+			/* mbuf stats disabled */
+			return NULL;
+#else
+			/* XXX TODO: implement new method */
+			return NULL;
+#endif
+#endif
+#else
 			return NULL;
 #endif
 			break;
@@ -562,7 +572,17 @@
 			long_return = (mbpool.pr_nget - mbpool.pr_nput)*mbpool.pr_size
 				+ (mclpool.pr_nget - mclpool.pr_nput)*mclpool.pr_size;
 #elif defined(MBSTAT_SYMBOL)
+#if __FreeBSD_version < 500021
 			long_return = mbstat.m_clusters - mbstat.m_clfree;	/* unlikely, but... */
+#else
+#if __FreeBSD_version < 500024
+			/* mbuf stats disabled */
+			return NULL;
+#else
+			/* XXX TODO: implement new method */
+			return NULL;
+#endif
+#endif
 #else
 			return NULL;
 #endif
