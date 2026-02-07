--- core/Common/3dParty/heif/heif.pri.orig	2025-10-13 15:33:25 UTC
+++ core/Common/3dParty/heif/heif.pri
@@ -7,9 +7,15 @@
 
 HEIF_BUILD_PATH = $$PWD/libheif/build/$$HEIF_BUILDS_PLATFORM_PREFIX/$$CORE_BUILDS_CONFIGURATION_PREFIX
 
-INCLUDEPATH += \
-	$$PWD/libheif/libheif/api \
-	$$HEIF_BUILD_PATH				# for heif_version.h
+#INCLUDEPATH += \
+#	$$PWD/libheif/libheif/api \
+#	$$HEIF_BUILD_PATH				# for heif_version.h
+
+core_freebsd {
+	INCLUDEPATH += %%LOCALBASE%%/include/libheif
+
+	LIBS += %%LOCALBASE%%/lib/libheif.so
+ }
 
 core_windows {
 	core_debug {
