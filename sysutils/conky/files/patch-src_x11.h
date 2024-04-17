--- src/x11.h.orig	2024-04-17 02:04:14 UTC
+++ src/x11.h
@@ -22,6 +22,7 @@
  *
  */
 
+#ifdef BUILD_X11
 #pragma once
 
 #include "config.h"
@@ -246,3 +247,5 @@ extern priv::use_xpmdb_setting use_xpmdb;
 #else
 extern priv::use_xpmdb_setting use_xpmdb;
 #endif
+
+#endif /* BUILD_X11 */
