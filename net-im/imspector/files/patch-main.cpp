--- main.cpp.orig	2010-02-23 20:21:10.000000000 +0300
+++ main.cpp	2011-11-08 19:05:36.000000000 +0400
@@ -17,11 +17,11 @@
 #include "imspector.h"
 
 /*! The default location for where to find the config file. */
-#define DEFAULT_CONFIG "/usr/etc/imspector/imspector.conf"
+#define DEFAULT_CONFIG "%%PREFIX%%/etc/imspector/imspector.conf"
 /*! The location of the logging process's UNIX socket. */
 #define LOGGING_SOCKET "/tmp/.imspectorlog"
 /*! The default place for where to find plugins. */
-#define DEFAULT_PLUGIN_DIR "/usr/lib/imspector"
+#define DEFAULT_PLUGIN_DIR "%%PREFIX%%/lib/imspector"
 
 #define DEFAULT_RESPONSE_PREFIX "Message from IMSpector: -="
 #define DEFAULT_RESPONSE_POSTFIX "=-"
