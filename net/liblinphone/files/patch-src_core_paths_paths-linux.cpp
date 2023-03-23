--- src/core/paths/paths-linux.cpp.orig	2023-03-17 13:29:37 UTC
+++ src/core/paths/paths-linux.cpp
@@ -24,6 +24,16 @@
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
