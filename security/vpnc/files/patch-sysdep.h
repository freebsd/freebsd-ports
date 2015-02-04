--- sysdep.h.orig	2008-11-19 20:36:12 UTC
+++ sysdep.h
@@ -86,6 +86,7 @@ int tun_get_hwaddr(int fd, char *dev, ui
 #define HAVE_FGETLN    1
 #define HAVE_UNSETENV  1
 #define HAVE_SETENV    1
+#define HAVE_GETLINE   1
 #endif
 
 /***************************************************************************/
@@ -97,6 +98,7 @@ int tun_get_hwaddr(int fd, char *dev, ui
 #define HAVE_FGETLN    1
 #define HAVE_UNSETENV  1
 #define HAVE_SETENV    1
+#define HAVE_GETLINE   1
 #endif
 
 /***************************************************************************/
