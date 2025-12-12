--- saa/saa.h.orig	2021-12-02 13:55:48 UTC
+++ saa/saa.h
@@ -40,6 +40,7 @@
 #else
 #include <xorg-server.h>
 #endif
+#undef bool
 #include <xf86.h>
 #include <damage.h>
 #include <picturestr.h>
