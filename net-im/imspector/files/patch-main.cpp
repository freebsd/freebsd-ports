--- main.cpp	Thu Mar 13 20:55:41 2008
+++ main.cpp	Mon Mar 17 15:07:27 2008
@@ -9,9 +9,9 @@
 
 #include "imspector.h"
 
-#define DEFAULT_CONFIG "/usr/etc/imspector/imspector.conf"
+#define DEFAULT_CONFIG "%%PREFIX%%/etc/imspector/imspector.conf"
 #define LOGGING_SOCKET "/tmp/.imspectorlog"
-#define DEFAULT_PLUGIN_DIR "/usr/lib/imspector"
+#define DEFAULT_PLUGIN_DIR "%%PREFIX%%/lib/imspector"
 
 std::vector<class ProtocolPlugin> protocolplugins;
 std::vector<class FilterPlugin> filterplugins;
