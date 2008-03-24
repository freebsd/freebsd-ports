--- src/kit/kit-file.c.orig	2007-11-28 16:32:08.000000000 -0500
+++ src/kit/kit-file.c	2007-12-24 14:48:35.000000000 -0500
@@ -283,7 +283,11 @@ _kit_get_num_fd (void)
         DIR *dir;
         char buf[128];
         ssize_t num;
+#ifdef HAVE_READDIR64
         struct dirent64 *d;
+#else
+	struct dirent *d;
+#endif
 
         num = -1;
 
@@ -296,7 +300,11 @@ _kit_get_num_fd (void)
         }
 
         num = -2;
+#ifdef HAVE_READDIR64
         while ((d = readdir64 (dir)) != NULL) {
+#else
+	while ((d = readdir (dir)) != NULL) {
+#endif
                 if (d->d_name == NULL)
                         continue;
                 num++;
