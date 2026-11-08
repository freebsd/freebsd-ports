--- hw/xfree86/loader/loadmod.c.orig	2026-10-30 22:07:53.083873000 -0700
+++ hw/xfree86/loader/loadmod.c	2026-10-30 22:09:42.022128000 -0700
@@ -520,16 +520,18 @@
     int len = 0;
     const char **ret = NULL;
     int subdirlen = strlen(subdir);
-    for (int i = 0; i < sizeof(stdSubdirs) / sizeof(*stdSubdirs); i++) {
-        int prefixsize = sizeof(stdSubdirs[i]);
-        char* dir = malloc(prefixsize + subdirlen);
+
+    for (const char **s = stdSubdirs; *s; s++) {
+        int prefixsize = strlen(*s);
+        char* dir = malloc(prefixsize + subdirlen + 1);
         if (!dir) {
             free(ret);
             return NULL;
         }
-        memcpy(dir, stdSubdirs[i], prefixsize - 1);
-        memcpy(dir + prefixsize - 1, subdir, subdirlen + 1);
 
+        memcpy(dir, *s, prefixsize);
+        memcpy(dir + prefixsize, subdir, subdirlen + 1);
+
         int sublen = 0;
         const char **subret = _LoaderListDir(dir, patternlist, &sublen);
         free(dir);
@@ -546,7 +548,8 @@
         }
 
         ret = tmp;
-        memcpy(ret + oldlen, subret, sublen);
+        for (int i = 0; i < sublen; i++)
+            ret[oldlen + i] = subret[i];
     }
     if (ret) {
         ret[len] = NULL;
