--- pxattr.cpp.orig	2013-02-02 17:45:27 UTC
+++ pxattr.cpp
@@ -802,7 +802,7 @@ void  printxattr(const string &path, con
 
 void delxattr(const string &path, const string& name) 
 {
-    if (pxattr::del(path, name) < 0) {
+    if (!pxattr::del(path, name)) {
 	perror("pxattr::del");
 	exit(1);
     }
