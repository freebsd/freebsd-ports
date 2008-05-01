--- src/polkit-grant/polkit-grant-helper-pam.c.orig	2008-04-08 12:23:22.000000000 -0400
+++ src/polkit-grant/polkit-grant-helper-pam.c	2008-04-21 23:55:43.000000000 -0400
@@ -41,6 +41,8 @@
 #include <syslog.h>
 #include <security/pam_appl.h>
 
+#include <kit/kit.h>
+
 #ifdef HAVE_SOLARIS
 #define LOG_AUTHPRIV    (10<<3)
 #endif
@@ -67,15 +69,8 @@ main (int argc, char *argv[])
         pam_h = NULL;
 
         /* clear the entire environment to avoid attacks using with libraries honoring environment variables */
-#ifdef HAVE_SOLARIS
-        extern char **environ;
-
-        if (environ != NULL)
-                environ[0] = NULL;
-#else
-        if (clearenv () != 0)
+        if (kit_clearenv () != 0)
                 goto error;
-#endif
         /* set a minimal environment */
         setenv ("PATH", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
 
