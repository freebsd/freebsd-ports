--- interpolation/sharedlib.c.orig	2018-12-14 06:44:18 UTC
+++ interpolation/sharedlib.c
@@ -61,8 +61,8 @@ void *share_file(const char* file) {
     char message[1024];
     char path[1024];
 
-    struct  stat64 s;
-    struct  stat64 s2;
+    struct  stat s;
+    struct  stat s2;
     int fd = -1;
     int err = 0;
     void *ptr = NULL;
@@ -183,9 +183,9 @@ void *share_file(const char* file) {
         goto error;
     }
 
-    if(stat64(path,&s))
+    if(stat(path,&s))
     {
-        sprintf(message,"ERR: sharedmem:stat64(%s)",path);
+        sprintf(message,"ERR: sharedmem:stat(%s)",path);
         err = -1;
         goto error;
     }
