https://github.com/newsboat/newsboat/pull/398

--- include/queuemanager.h.orig	2018-12-29 16:22:22 UTC
+++ include/queuemanager.h
@@ -1,6 +1,7 @@
 #ifndef NEWSBOAT_QUEUEMANAGER_H_
 #define NEWSBOAT_QUEUEMANAGER_H_
 
+#include <ctime>
 #include <memory>
 #include <string>
 
