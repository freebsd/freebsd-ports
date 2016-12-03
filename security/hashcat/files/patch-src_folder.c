--- src/folder.c.orig	2016-12-02 14:00:23 UTC
+++ src/folder.c
@@ -65,9 +65,7 @@ static int get_exec_path (char *exec_pat
 
   sysctl (mib, 4, exec_path, &size, NULL, 0);
 
-  const ssize_t len = readlink (tmp, exec_path, exec_path_sz - 1);
-
-  if (len == -1) return -1;
+  const size_t len = strlen (exec_path);
 
   #else
   #error Your Operating System is not supported or detected
