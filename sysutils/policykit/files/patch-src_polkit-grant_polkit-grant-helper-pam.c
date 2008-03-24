--- src/polkit-grant/polkit-grant-helper-pam.c.orig	2007-11-28 16:28:31.000000000 -0500
+++ src/polkit-grant/polkit-grant-helper-pam.c	2007-12-23 02:01:46.000000000 -0500
@@ -38,6 +38,8 @@
 #include <syslog.h>
 #include <security/pam_appl.h>
 
+#include <polkit/polkit.h>
+
 /* Development aid: define PGH_DEBUG to get debugging output. Do _NOT_
  * enable this in production builds; it may leak passwords and other
  * sensitive information.
@@ -60,7 +62,7 @@ main (int argc, char *argv[])
         pam_h = NULL;
 
         /* clear the entire environment to avoid attacks using with libraries honoring environment variables */
-        if (clearenv () != 0)
+        if (polkit_sysdeps_clearenv () != 0)
                 goto error;
         /* set a minimal environment */
         setenv ("PATH", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
