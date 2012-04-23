--- api/boinc_api.h.orig	2012-04-20 16:15:13.000000000 +0200
+++ api/boinc_api.h	2012-04-20 16:17:11.000000000 +0200
@@ -29,6 +29,8 @@
 extern "C" {
 #endif
 
+#include <cstddef>
+
 // parameters passed to the BOINC runtime system
 //
 typedef struct BOINC_OPTIONS {
