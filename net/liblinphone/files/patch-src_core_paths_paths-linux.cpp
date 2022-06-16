--- src/core/paths/paths-linux.cpp.orig	2022-06-16 11:20:59 UTC
+++ src/core/paths/paths-linux.cpp
@@ -22,6 +22,16 @@
 
 #include "paths-linux.h"
 
+#ifdef __FreeBSD__
+/* get_current_dir_name() is a GNU extension.
+ *
+ */
+char *get_current_dir_name()
+{
+return getcwd(nullptr, 0);
+}
+#endif
+
 // =============================================================================
 
 using namespace std;
