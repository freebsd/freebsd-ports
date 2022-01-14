--- src/obs-ndi.cpp.orig	2022-01-14 17:54:22 UTC
+++ src/obs-ndi.cpp
@@ -198,7 +198,7 @@ const NDIlib_v4* load_ndilib()
 {
 	QStringList locations;
 	locations << QString(qgetenv(NDILIB_REDIST_FOLDER));
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 	locations << "/usr/lib";
 	locations << "/usr/local/lib";
 #endif
