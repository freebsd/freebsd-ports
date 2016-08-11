--- base/gp_unix.c.orig	2008-09-09 20:31:37 UTC
+++ base/gp_unix.c
@@ -50,6 +50,7 @@ extern char *getenv(const char *);
  * and applied as a patch (preferable).
  */
 #include <sys/types.h>
+#include <limits.h>
 #include <dirent.h>
 #include <dlfcn.h>
 #include <string.h>
@@ -59,26 +60,25 @@ gp_init(void)
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
+	continue;
+    handle = dlopen(buff, RTLD_NOW);
+    if (handle == NULL)
+	continue;
+    gs_shared_init = dlsym(handle, "gs_shared_init");
+    if (gs_shared_init != NULL)
 	(*gs_shared_init)();
-      } else {
-      }
-    }
   }
 
   closedir(dir);
