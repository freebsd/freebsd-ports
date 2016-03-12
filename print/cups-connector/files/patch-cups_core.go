--- cups/core.go.orig	2016-03-12 14:17:25 UTC
+++ cups/core.go
@@ -9,8 +9,8 @@
 package cups
 
 /*
-#cgo freebsd CFLAGS: -I/usr/local/include
-#cgo freebsd LDFLAGS: -L/usr/local/lib
+#cgo freebsd CFLAGS: -I%%PREFIX%%/include
+#cgo freebsd LDFLAGS: -L%%PREFIX%%/lib
 #include "cups.h"
 */
 import "C"
