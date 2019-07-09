--- src/framework/engine.h.orig	2019-07-05 17:52:32 UTC
+++ src/framework/engine.h
@@ -6,6 +6,8 @@
 
 #pragma once
 
+#include <sys/select.h>
+
 #include <thread>
 #include <map>
 #include <vector>
