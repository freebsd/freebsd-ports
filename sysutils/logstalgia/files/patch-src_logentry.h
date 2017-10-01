--- src/logentry.h.orig	2017-09-29 02:04:47 UTC
+++ src/logentry.h
@@ -24,6 +24,10 @@
 #include <vector>
 #include <map>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+
 class LogEntry {
 
 private:
