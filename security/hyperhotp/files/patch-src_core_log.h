--- src/core/log.h.orig	2021-10-05 10:43:22 UTC
+++ src/core/log.h
@@ -1,6 +1,6 @@
 #pragma once
 
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 #include <stddef.h>
 
 void log_fatal(const char* msg);
