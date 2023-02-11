--- src/core/paths/paths-linux.cpp.orig	2022-08-08 14:58:59 UTC
+++ src/core/paths/paths-linux.cpp
@@ -23,6 +23,16 @@
 #include "paths-linux.h"
 #include "linphone/api/c-factory.h"
 
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
