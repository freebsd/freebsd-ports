--- agent/mibgroup/host/hr_storage.c.orig	Thu Jul  4 09:00:11 2002
+++ agent/mibgroup/host/hr_storage.c	Thu Jun 24 16:47:34 2004
@@ -32,7 +32,7 @@
 #else
 #if HAVE_VM_VM_H
 #include <vm/vm.h>
-#if HAVE_MACHINE_TYPES_H
+#if HAVE_MACHINE_TYPES_H && (!defined(__FreeBSD__) || __FreeBSD_version < 500000)
 #include <machine/types.h>
 #endif
 #if HAVE_SYS_VMMETER_H
@@ -148,7 +148,7 @@
 #define HRFS_mount	mnt_mountp
 #define HRFS_statfs	statvfs
 
-#elif defined(HAVE_STATVFS)
+#elif defined(HAVE_STATVFS) && defined(HAVE_MNTENT)
 
 extern struct mntent *HRFS_entry;
 extern int fscount;
@@ -553,7 +553,7 @@
 	    }
 	case HRSTORE_UNITS:
 	    if ( store_idx < HRS_TYPE_FS_MAX )
-#if STRUCT_STATVFS_HAS_F_FRSIZE
+#if defined(STRUCT_STATVFS_HAS_F_FRSIZE) && defined(HAVE_MNTENT)
 		long_return = stat_buf.f_frsize;
 #else
 		long_return = stat_buf.f_bsize;
@@ -634,7 +634,15 @@
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
@@ -693,7 +701,15 @@
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
@@ -723,7 +739,11 @@
 #if !defined(linux) && !defined(solaris2) && !defined(hpux10) && !defined(hpux11)
 		case HRS_TYPE_MBUF:
 #if defined(MBSTAT_SYMBOL)
+#if defined(__FreeBSD__) && __FreeBSD_version >= 502113
+			long_return = mbstat.m_mcfail + mbstat.m_mpfail;
+#else
 			long_return = mbstat.m_drops;
+#endif
 #elif defined(NO_DUMMY_VALUES)
 			return NULL;
 #else
