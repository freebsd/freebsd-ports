--- src/polkit-dbus/polkit-resolve-exe-helper.c.orig	2008-04-08 12:23:22.000000000 -0400
+++ src/polkit-dbus/polkit-resolve-exe-helper.c	2008-04-21 23:41:09.000000000 -0400
@@ -40,6 +40,9 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef HAVE_FREEBSD
+#include <sys/param.h>
+#endif
 #include <security/pam_appl.h>
 #include <grp.h>
 #include <pwd.h>
@@ -76,15 +79,8 @@ main (int argc, char *argv[])
         ret = 1;
 
         /* clear the entire environment to avoid attacks using with libraries honoring environment variables */
-#ifdef HAVE_SOLARIS
-	extern char **environ;
-
-	if (environ != NULL)
-		environ[0] = NULL;
-#else
-        if (clearenv () != 0)
+        if (kit_clearenv () != 0)
                 goto out;
-#endif
         /* set a minimal environment */
         setenv ("PATH", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
 
