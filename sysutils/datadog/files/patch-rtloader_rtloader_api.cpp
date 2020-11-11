--- rtloader/rtloader/api.cpp.orig	2020-05-11 15:38:36 UTC
+++ rtloader/rtloader/api.cpp
@@ -25,6 +25,9 @@
 #elif _WIN32
 #    define DATADOG_AGENT_TWO "libdatadog-agent-two.dll"
 #    define DATADOG_AGENT_THREE "libdatadog-agent-three.dll"
+#elif __FreeBSD__
+#    define DATADOG_AGENT_TWO "libdatadog-agent-two.so"
+#    define DATADOG_AGENT_THREE "libdatadog-agent-three.so"
 #else
 #    error Platform not supported
 #endif
