--- kget/ui/metalinkcreator/metalinker.cpp	2010/12/22 13:31:19	1208598
+++ kget/ui/metalinkcreator/metalinker.cpp	2011/04/09 09:26:37	1227471
@@ -583,7 +583,13 @@
         return false;
     }
 
-    if (name.contains(QRegExp("$(\\.\\.?)?/")) || name.contains("/../") || name.endsWith("/..")) {
+    if (name.endsWith('/')) {
+        kError(5001) << "Name attribute of Metalink::File does not contain a file name:" << name;
+        return false;
+    }
+
+    const QStringList components = name.split('/');
+    if (name.startsWith('/') || components.contains("..") || components.contains(".")) {
         kError(5001) << "Name attribute of Metalink::File contains directory traversal directives:" << name;
         return false;
     }
