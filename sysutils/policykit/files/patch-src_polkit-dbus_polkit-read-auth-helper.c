--- src/polkit-dbus/polkit-read-auth-helper.c.orig	2007-11-28 23:33:10.000000000 -0500
+++ src/polkit-dbus/polkit-read-auth-helper.c	2007-12-24 14:53:38.000000000 -0500
@@ -39,6 +39,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/stat.h>
 #include <security/pam_appl.h>
 #include <grp.h>
@@ -156,7 +157,11 @@ dump_auths_all (const char *root)
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
@@ -173,7 +178,11 @@ dump_auths_all (const char *root)
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
@@ -282,7 +291,7 @@ main (int argc, char *argv[])
 
 #ifndef POLKIT_BUILD_TESTS
         /* clear the entire environment to avoid attacks using with libraries honoring environment variables */
-        if (clearenv () != 0)
+        if (polkit_sysdeps_clearenv () != 0)
                 goto out;
         /* set a minimal environment */
         setenv ("PATH", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
