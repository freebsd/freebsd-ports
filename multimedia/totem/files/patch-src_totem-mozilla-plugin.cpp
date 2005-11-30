--- src/totem-mozilla-plugin.cpp.orig	Tue Nov  8 21:50:10 2005
+++ src/totem-mozilla-plugin.cpp	Tue Nov  8 21:50:27 2005
@@ -27,6 +27,7 @@
 #include <stdint.h>
 #include <unistd.h>
 #include <fcntl.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include <string.h>
 
