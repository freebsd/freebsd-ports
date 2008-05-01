--- src/polkit-grant/polkit-revoke-helper.c.orig	2008-04-08 12:23:22.000000000 -0400
+++ src/polkit-grant/polkit-revoke-helper.c	2008-04-21 23:38:11.000000000 -0400
@@ -112,15 +112,8 @@ main (int argc, char *argv[])
 
 #ifndef POLKIT_BUILD_TESTS
         /* clear the entire environment to avoid attacks using with libraries honoring environment variables */
-#ifdef HAVE_SOLARIS
-        extern char **environ;
-
-        if (environ != NULL)
-                environ[0] = NULL;
-#else
-        if (clearenv () != 0)
+        if (kit_clearenv () != 0)
                 goto out;
-#endif
         /* set a minimal environment */
         setenv ("PATH", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
 #endif
