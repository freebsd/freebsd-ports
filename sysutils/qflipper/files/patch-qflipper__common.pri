--- qflipper_common.pri.orig	2022-11-27 18:49:46 UTC
+++ qflipper_common.pri
@@ -5,7 +5,7 @@ unix:!macx {
 unix:!macx {
     DEFINES += USB_BACKEND_LIBUSB
     CONFIG += link_pkgconfig
-    PKGCONFIG += libusb-1.0 zlib
+    LIBS += -lusb -lz
 
     isEmpty(PREFIX): PREFIX = /usr
 
@@ -27,20 +27,11 @@ unix:!macx {
     error("Unsupported OS or compiler")
 }
 
-GIT_VERSION = $$system("git describe --tags --abbrev=0","lines", HAS_VERSION)
-!equals(HAS_VERSION, 0) {
-    GIT_VERSION = unknown
-}
+GIT_VERSION = 1.3.3
 
-GIT_COMMIT = $$system("git rev-parse --short=8 HEAD","lines", HAS_COMMIT)
-!equals(HAS_COMMIT, 0) {
-    GIT_COMMIT = unknown
-}
+GIT_COMMIT = bfce851
 
-GIT_TIMESTAMP = $$system("git log -1 --pretty=format:%ct","lines", HAS_TIMESTAMP)
-!equals(HAS_TIMESTAMP, 0) {
-    GIT_TIMESTAMP = 0
-}
+GIT_TIMESTAMP = 1705727789
 
 DEFINES += APP_NAME=\\\"$$NAME\\\" \
            APP_VERSION=\\\"$$GIT_VERSION\\\" \
