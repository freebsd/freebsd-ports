--- agent/mibgroup/host/hr_storage.c.orig	Thu Jul  4 22:00:31 2002
+++ agent/mibgroup/host/hr_storage.c	Mon Jul 22 14:38:58 2002
@@ -148,7 +148,7 @@
 #define HRFS_mount	mnt_mountp
 #define HRFS_statfs	statvfs
 
-#elif defined(HAVE_STATVFS)
+#elif defined(HAVE_STATVFS) && defined(HAVE_MNTENT)
 
 extern struct mntent *HRFS_entry;
 extern int      fscount;
@@ -563,7 +563,7 @@
         }
     case HRSTORE_UNITS:
         if (store_idx < HRS_TYPE_FS_MAX)
-#if STRUCT_STATVFS_HAS_F_FRSIZE
+#if defined(STRUCT_STATVFS_HAS_F_FRSIZE) && defined(HAVE_MNTENT)
             long_return = stat_buf.f_frsize;
 #else
             long_return = stat_buf.f_bsize;
@@ -646,7 +646,15 @@
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
@@ -704,7 +712,15 @@
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
