--- agent/scim-bridge-agent-signal-listener.cpp.orig	2008-11-02 06:44:50.000000000 +0000
+++ agent/scim-bridge-agent-signal-listener.cpp
@@ -22,6 +22,7 @@
 #include <signal.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 
 #include <sys/socket.h>
 #include <sys/types.h>
