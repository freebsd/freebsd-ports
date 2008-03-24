--- src/polkit-dbus/polkit-set-default-helper.c.orig	2007-12-23 01:21:04.000000000 -0500
+++ src/polkit-dbus/polkit-set-default-helper.c	2007-12-23 01:21:11.000000000 -0500
@@ -127,7 +127,7 @@ main (int argc, char *argv[])
 
         ret = 1;
         /* clear the entire environment to avoid attacks using with libraries honoring environment variables */
-        if (clearenv () != 0)
+        if (polkit_sysdeps_clearenv () != 0)
                 goto out;
         /* set a minimal environment */
         setenv ("PATH", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
