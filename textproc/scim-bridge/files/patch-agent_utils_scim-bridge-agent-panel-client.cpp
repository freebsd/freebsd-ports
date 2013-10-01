--- agent/utils/scim-bridge-agent-panel-client.cpp.orig	2009-01-17 17:20:15.000000000 +0000
+++ agent/utils/scim-bridge-agent-panel-client.cpp
@@ -20,6 +20,7 @@
 
 #include <errno.h>
 #include <string.h>
+#include <unistd.h>
 
 #include <sys/stat.h>
 #include <sys/types.h>
