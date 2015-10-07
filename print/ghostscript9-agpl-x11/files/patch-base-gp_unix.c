--- base/gp_unix.c.orig	2015-08-22 03:07:24.257409000 +0900
+++ base/gp_unix.c	2015-08-22 03:08:15.753173000 +0900
@@ -52,6 +52,7 @@
  * and applied as a patch (preferable).
  */
 #include <sys/types.h>
+#include <limits.h>
 #include <dirent.h>
 #include <dlfcn.h>
 #include <string.h>
@@ -61,26 +62,25 @@
 {
   DIR*           dir = NULL;
   struct dirent* dirent;
-  char           buff[1024];
+  char           buff[PATH_MAX];
   char*          pbuff;
   void*          handle;
   void           (*gs_shared_init)(void);
 
-  strncpy(buff, GS_DEVS_SHARED_DIR, sizeof(buff) - 2);
-  pbuff = buff + strlen(buff);
-  *pbuff++ = '/'; *pbuff = '\0';
-
   dir = opendir(GS_DEVS_SHARED_DIR);
   if (dir == 0) return;
 
   while ((dirent = readdir(dir)) != 0) {
-    strncpy(pbuff, dirent->d_name, sizeof(buff) - (pbuff - buff) - 1);
-    if ((handle = dlopen(buff, RTLD_NOW)) != 0) {
-      if ((gs_shared_init = dlsym(handle, "gs_shared_init")) != 0) {
+    snprintf(buff, sizeof(buff), "%s/%s", GS_DEVS_SHARED_DIR, dirent->d_name);
+    pbuff = buff + strlen(buff) - 3;
+    if (strcmp(pbuff, ".so") != 0)
+        continue;
+    handle = dlopen(buff, RTLD_NOW);
+    if (handle == NULL)
+        continue;
+    gs_shared_init = dlsym(handle, "gs_shared_init");
+    if (gs_shared_init != NULL)
         (*gs_shared_init)();
-      } else {
-      }
-    }
   }
 
   closedir(dir);
