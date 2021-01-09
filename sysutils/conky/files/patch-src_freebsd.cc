--- src/freebsd.cc.orig	2020-07-27 12:01:52 UTC
+++ src/freebsd.cc
@@ -49,7 +49,9 @@
 #include <unistd.h>
 
 #include <dev/acpica/acpiio.h>
+#if 0
 #include <dev/wi/if_wavelan_ieee.h>
+#endif
 
 #include <mutex>
 
