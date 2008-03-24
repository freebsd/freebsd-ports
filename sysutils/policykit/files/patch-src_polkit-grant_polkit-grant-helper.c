--- src/polkit-grant/polkit-grant-helper.c.orig	2007-12-23 01:23:13.000000000 -0500
+++ src/polkit-grant/polkit-grant-helper.c	2007-12-23 01:23:19.000000000 -0500
@@ -546,7 +546,7 @@ main (int argc, char *argv[])
         ret = 3;
 
         /* clear the entire environment to avoid attacks using with libraries honoring environment variables */
-        if (clearenv () != 0)
+        if (polkit_sysdeps_clearenv () != 0)
                 goto out;
         /* set a minimal environment */
         setenv ("PATH", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
