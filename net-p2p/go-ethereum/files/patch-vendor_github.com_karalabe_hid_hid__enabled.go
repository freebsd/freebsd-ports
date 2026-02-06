--- vendor/github.com/karalabe/hid/hid_enabled.go.orig	2026-02-04 22:48:45 UTC
+++ vendor/github.com/karalabe/hid/hid_enabled.go
@@ -31,7 +31,7 @@ specifically for the linux platform, below.
 #cgo windows LDFLAGS: -lsetupapi
 
 #cgo freebsd CFLAGS: -DOS_FREEBSD
-#cgo freebsd LDFLAGS: -lusb
+#cgo freebsd LDFLAGS: -lhidapi -lusb
 
 #cgo openbsd CFLAGS: -DOS_OPENBSD
 
@@ -64,8 +64,9 @@ specifically for the linux platform, below.
 #elif OS_WINDOWS
 	#include "hidapi/windows/hid.c"
 #elif OS_FREEBSD
-	#include <libusb.h>
-	#include "hidapi/libusb/hid.c"
+	#include <stdlib.h>
+	#include <wchar.h>
+	#include <hidapi/hidapi.h>
 #elif DOS_OPENBSD
 	#include "hidapi/libusb/hid.c"
 #endif
