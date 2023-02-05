--- src/main.c.orig	2022-11-30 10:30:55 UTC
+++ src/main.c
@@ -44,6 +44,7 @@ int extended_info = 0;
 int follow_symlinks = 0;
 int follow_firmlinks = 1;
 int confirm_quit = 0;
+int exclude_kernfs = 0;
 int si = 0;
 int show_as = 0;
 int graph = 1;
