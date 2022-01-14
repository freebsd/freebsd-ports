--- lib/ndi/Processing.NDI.Lib.h.orig	2022-01-14 18:57:16 UTC
+++ lib/ndi/Processing.NDI.Lib.h
@@ -60,7 +60,7 @@
 #			define NDILIB_REDIST_FOLDER "NDI_RUNTIME_DIR_V4"
 #			define NDILIB_REDIST_URL    "http://new.tk/NDIRedistV4Apple"
 #		else // __APPLE__
-#			define NDILIB_LIBRARY_NAME  "libndi.so.4"
+#			define NDILIB_LIBRARY_NAME  "libndi.so"
 #			define NDILIB_REDIST_FOLDER "NDI_RUNTIME_DIR_V4"
 #			define NDILIB_REDIST_URL    ""
 #		endif // __APPLE__
