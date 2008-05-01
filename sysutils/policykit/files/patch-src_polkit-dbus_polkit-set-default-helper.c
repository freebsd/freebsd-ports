--- src/polkit-dbus/polkit-set-default-helper.c.orig	2008-04-08 16:36:47.000000000 -0400
+++ src/polkit-dbus/polkit-set-default-helper.c	2008-04-21 23:41:51.000000000 -0400
@@ -128,15 +128,8 @@ main (int argc, char *argv[])
 
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
 
