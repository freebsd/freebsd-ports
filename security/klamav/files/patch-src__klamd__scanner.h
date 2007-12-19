--- src/klamd/scanner.h.orig	2007-12-19 08:34:32.000000000 -0200
+++ src/klamd/scanner.h	2007-12-19 08:34:52.000000000 -0200
@@ -33,4 +33,6 @@
 
 int checksymlink(const char *path);
 
+extern int cli_gentempfd(const char *dir, char **name, int *fd);
+
 #endif
