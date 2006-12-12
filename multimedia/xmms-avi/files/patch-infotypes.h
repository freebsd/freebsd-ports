--- include/infotypes.h.orig	Mon Dec 11 18:13:09 2006
+++ include/infotypes.h	Mon Dec 11 18:13:44 2006
@@ -1,6 +1,10 @@
 #ifndef INFOTYPES_H
 #define INFOTYPES_H
 
+#ifdef max
+#undef max
+#endif
+
 #include <vector>
 #include <string>
 #include <map>
