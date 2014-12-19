--- hw/xfree86/loader/loadmod.c.orig	2014-04-12 15:29:14 UTC
+++ hw/xfree86/loader/loadmod.c
@@ -490,7 +490,7 @@ LoaderListDirs(const char **subdirlist, 
     char **elem;
     const char **subdirs;
     const char **s;
-    PatternPtr patterns;
+    PatternPtr patterns = NULL;
     PatternPtr p;
     DIR *d;
     struct dirent *dp;
