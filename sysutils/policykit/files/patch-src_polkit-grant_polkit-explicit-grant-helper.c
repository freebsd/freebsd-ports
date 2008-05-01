--- src/polkit-grant/polkit-explicit-grant-helper.c.orig	2008-04-08 12:23:22.000000000 -0400
+++ src/polkit-grant/polkit-explicit-grant-helper.c	2008-04-21 23:34:12.000000000 -0400
@@ -70,15 +70,8 @@ main (int argc, char *argv[])
         ret = 1;
 
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
 
