--- src/wazuh_modules/wm_database.c	2024-01-05 08:38:26.000000000 -0500
+++ src/wazuh_modules/wm_database.c	2024-01-11 15:18:58.255136000 -0500
@@ -16,6 +16,11 @@
 #include "addagent/manage_agents.h" // FILE_SIZE
 #include "external/cJSON/cJSON.h"
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+#endif
+
 #ifndef CLIENT
 
 #ifdef INOTIFY_ENABLED
