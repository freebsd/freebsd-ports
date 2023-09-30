--- libng/plugins/Subdir.mk.orig	2020-05-15 23:32:25 UTC
+++ libng/plugins/Subdir.mk
@@ -28,9 +28,7 @@ TARGETS-plugins += \
 	libng/plugins/drv0-libv4l.so
 endif
 ifeq ($(FOUND_OS),bsd)
-TARGETS-plugins += \
-	libng/plugins/drv0-bsd.so \
-	libng/plugins/snd-oss.so
+TARGETS-plugins += libng/plugins/snd-oss.so
 endif
 
 GONE-plugins := \
