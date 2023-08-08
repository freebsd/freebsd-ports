--- src/x11.h.orig	2022-12-26 18:54:10 UTC
+++ src/x11.h
@@ -22,6 +22,7 @@
  *
  */
 
+#ifdef BUILD_X11
 #pragma once
 
 #include <X11/Xatom.h>
@@ -157,3 +158,5 @@ extern priv::use_xpmdb_setting use_xpmdb;
 #else
 extern priv::use_xpmdb_setting use_xpmdb;
 #endif
+
+#endif /* BUILD_X11 */
