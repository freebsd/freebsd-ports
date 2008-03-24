--- src/polkit-grant/polkit-revoke-helper.c.orig	2007-12-23 01:22:38.000000000 -0500
+++ src/polkit-grant/polkit-revoke-helper.c	2007-12-23 01:22:47.000000000 -0500
@@ -109,7 +109,7 @@ main (int argc, char *argv[])
 
 #ifndef POLKIT_BUILD_TESTS
         /* clear the entire environment to avoid attacks using with libraries honoring environment variables */
-        if (clearenv () != 0)
+        if (polkit_sysdeps_clearenv () != 0)
                 goto out;
         /* set a minimal environment */
         setenv ("PATH", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
