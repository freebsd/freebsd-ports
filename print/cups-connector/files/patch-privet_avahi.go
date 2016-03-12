--- privet/avahi.go.orig	2016-03-12 14:17:35 UTC
+++ privet/avahi.go
@@ -9,8 +9,8 @@
 package privet
 
 // #cgo linux LDFLAGS: -lavahi-client -lavahi-common
-// #cgo freebsd CFLAGS: -I/usr/local/include
-// #cgo freebsd LDFLAGS: -L/usr/local/lib -lavahi-client -lavahi-common
+// #cgo freebsd CFLAGS: -I%%PREFIX%%/include
+// #cgo freebsd LDFLAGS: -L%%PREFIX%%/lib -lavahi-client -lavahi-common
 // #include "avahi.h"
 import "C"
 import (
