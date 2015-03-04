--- sysdep.h.orig	2008-11-19 21:36:12.000000000 +0100
+++ sysdep.h	2015-03-03 21:35:27.443313082 +0100
@@ -75,17 +75,20 @@
 /***************************************************************************/
 #if defined(__FreeBSD_kernel__)
 #define HAVE_SA_LEN 1
+/* %%FREEBSD_IPLEN_FIX%% */
 #endif
 
 /***************************************************************************/
 #if defined(__FreeBSD__)
 #define HAVE_SA_LEN 1
+/* %%FREEBSD_IPLEN_FIX%% */
 
 #define HAVE_VASPRINTF 1
 #define HAVE_ASPRINTF  1
 #define HAVE_FGETLN    1
 #define HAVE_UNSETENV  1
 #define HAVE_SETENV    1
+#define HAVE_GETLINE   1
 #endif
 
 /***************************************************************************/
@@ -97,6 +100,7 @@
 #define HAVE_FGETLN    1
 #define HAVE_UNSETENV  1
 #define HAVE_SETENV    1
+#define HAVE_GETLINE   1
 #endif
 
 /***************************************************************************/
