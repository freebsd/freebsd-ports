--- agent/mibgroup/host/hr_storage.c.orig	Mon Mar 18 22:39:56 2002
+++ agent/mibgroup/host/hr_storage.c	Thu Aug 29 11:54:11 2002
@@ -145,7 +145,7 @@
 #define HRFS_mount	mnt_mountp
 #define HRFS_statfs	statvfs
 
-#elif defined(HAVE_STATVFS)
+#elif defined(HAVE_STATVFS) && defined(HAVE_MNTENT)
 
 extern struct mntent *HRFS_entry;
 extern int fscount;
@@ -520,7 +520,7 @@
 	    }
 	case HRSTORE_UNITS:
 	    if ( store_idx < HRS_TYPE_FS_MAX )
-#if STRUCT_STATVFS_HAS_F_FRSIZE
+#if defined(STRUCT_STATVFS_HAS_F_FRSIZE) && defined(HAVE_MNTENT)
 		long_return = stat_buf.f_frsize;
 #else
 		long_return = stat_buf.f_bsize;
@@ -601,7 +601,15 @@
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
@@ -660,7 +668,15 @@
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
