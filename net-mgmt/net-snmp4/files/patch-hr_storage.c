--- agent/mibgroup/host/hr_storage.c.orig	2006-06-20 09:29:35.000000000 +0000
+++ agent/mibgroup/host/hr_storage.c	2008-04-30 06:08:02.000000000 +0000
@@ -39,7 +39,7 @@
 #else
 #if HAVE_VM_VM_H
 #include <vm/vm.h>
-#if HAVE_MACHINE_TYPES_H
+#if HAVE_MACHINE_TYPES_H && (!defined(__FreeBSD__) || __FreeBSD_version < 500000)
 #include <machine/types.h>
 #endif
 #if HAVE_SYS_VMMETER_H
@@ -162,7 +162,7 @@
 #define HRFS_statfs	statvfs
 #define HRFS_mount	f_mntonname
 
-#elif defined(HAVE_STATVFS)
+#elif defined(HAVE_STATVFS) && defined(HAVE_MNTENT)
 
 extern struct mntent *HRFS_entry;
 extern int fscount;
@@ -568,7 +568,7 @@
 	    }
 	case HRSTORE_UNITS:
 	    if ( store_idx < HRS_TYPE_FS_MAX )
-#if STRUCT_STATVFS_HAS_F_FRSIZE
+#if defined(STRUCT_STATVFS_HAS_F_FRSIZE) && defined(HAVE_MNTENT)
 		long_return = stat_buf.f_frsize;
 #else
 		long_return = stat_buf.f_bsize;
@@ -649,7 +649,15 @@
 			for (i = 0; i < sizeof(mbstat.m_mtypes)/sizeof(mbstat.m_mtypes[0]); i++)
 			    long_return += mbstat.m_mtypes[i];
 #elif defined(MBSTAT_SYMBOL) && defined(STRUCT_MBSTAT_HAS_M_MBUFS)
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
@@ -708,7 +716,15 @@
 				+ (mclpool.pr_nget - mclpool.pr_nput)
 				    * mclpool.pr_size;
 #elif defined(MBSTAT_SYMBOL) && defined(STRUCT_MBSTAT_HAS_M_CLUSTERS)
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
@@ -738,7 +754,11 @@
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
