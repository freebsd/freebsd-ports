--- samba/include/config.h.orig	Fri Jun 14 00:44:17 2002
+++ samba/include/config.h	Fri Jun 14 00:42:22 2002
@@ -106,7 +106,7 @@
 /* #undef FTRUNCATE_NEEDS_ROOT */
 /* #undef HAVE_TRAPDOOR_UID */
 /* #undef HAVE_ROOT */
-/* #undef HAVE_UNION_SEMUN */
+#define HAVE_UNION_SEMUN 1
 #define HAVE_GETTIMEOFDAY_TZ 1
 /* #undef HAVE_SOCK_SIN_LEN */
 /* #undef STAT_READ_FILSYS */
@@ -745,7 +745,7 @@
 #define HAVE_SECURITY_PAM_APPL_H 1
 
 /* Define if you have the <shadow.h> header file.  */
-#define HAVE_SHADOW_H 1
+#undef HAVE_SHADOW_H 
 
 /* Define if you have the <stdarg.h> header file.  */
 #define HAVE_STDARG_H 1
@@ -760,7 +760,7 @@
 #define HAVE_STRINGS_H 1
 
 /* Define if you have the <stropts.h> header file.  */
-#define HAVE_STROPTS_H 1
+#undef HAVE_STROPTS_H
 
 /* Define if you have the <sys/acl.h> header file.  */
 /* #undef HAVE_SYS_ACL_H */
@@ -829,10 +829,10 @@
 /* #undef HAVE_SYS_SOCKIO_H */
 
 /* Define if you have the <sys/statfs.h> header file.  */
-#define HAVE_SYS_STATFS_H 1
+#undef HAVE_SYS_STATFS_H 
 
 /* Define if you have the <sys/statvfs.h> header file.  */
-#define HAVE_SYS_STATVFS_H 1
+#undef HAVE_SYS_STATVFS_H
 
 /* Define if you have the <sys/syscall.h> header file.  */
 #define HAVE_SYS_SYSCALL_H 1
@@ -847,7 +847,7 @@
 #define HAVE_SYS_UNISTD_H 1
 
 /* Define if you have the <sys/vfs.h> header file.  */
-#define HAVE_SYS_VFS_H 1
+#undef HAVE_SYS_VFS_H
 
 /* Define if you have the <sys/wait.h> header file.  */
 #define HAVE_SYS_WAIT_H 1
