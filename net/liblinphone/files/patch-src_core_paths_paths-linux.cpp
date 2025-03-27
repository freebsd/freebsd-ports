--- src/core/paths/paths-linux.cpp.orig	2025-03-20 22:21:32 UTC
+++ src/core/paths/paths-linux.cpp
@@ -24,6 +24,16 @@
 #include "linphone/api/c-factory.h"
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
