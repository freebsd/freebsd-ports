--- libng/plugins/Subdir.mk.orig	2020-03-18 04:43:15 UTC
+++ libng/plugins/Subdir.mk
@@ -28,9 +28,11 @@ TARGETS-plugins += \
 	libng/plugins/drv0-libv4l.so
 endif
 ifeq ($(FOUND_OS),bsd)
+ifeq ($(HAVE_BKTR),yes)
 TARGETS-plugins += \
-	libng/plugins/drv0-bsd.so \
-	libng/plugins/snd-oss.so
+	libng/plugins/drv0-bsd.so
+endif
+TARGETS-plugins += libng/plugins/snd-oss.so
 endif
 
 GONE-plugins := \
