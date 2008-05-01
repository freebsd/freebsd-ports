--- src/polkit-dbus/polkit-read-auth-helper.c.orig	2008-04-08 12:23:22.000000000 -0400
+++ src/polkit-dbus/polkit-read-auth-helper.c	2008-04-21 23:40:19.000000000 -0400
@@ -39,6 +39,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <grp.h>
 #include <pwd.h>
@@ -159,7 +160,11 @@ dump_auths_all (const char *root)
 {
         DIR *dir;
         int dfd;
+#ifdef HAVE_READDIR64
         struct dirent64 *d;
+#else
+	struct dirent *d;
+#endif
         polkit_bool_t ret;
 
         ret = FALSE;
@@ -176,7 +181,11 @@ dump_auths_all (const char *root)
                 goto out;
         }
 
+#ifdef HAVE_READDIR64
         while ((d = readdir64(dir)) != NULL) {
+#else
+	while ((d = readdir(dir)) != NULL) {
+#endif
                 unsigned int n, m;
                 uid_t uid;
                 size_t name_len;
@@ -291,15 +300,8 @@ main (int argc, char *argv[])
 
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
