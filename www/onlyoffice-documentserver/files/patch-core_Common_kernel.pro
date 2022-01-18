--- core/Common/kernel.pro.orig	2021-09-30 12:13:32 UTC
+++ core/Common/kernel.pro
@@ -42,6 +42,18 @@ core_windows {
     LIBS += -lRpcrt4
     LIBS += -lShell32
 }
+core_freebsd {
+    CONFIG += use_external_download
+
+    use_external_download {
+        DEFINES += USE_EXTERNAL_DOWNLOAD
+    } else {
+        include(../Common/3dParty/curl/curl.pri)
+    }
+
+    SOURCES += \
+        ./FileDownloader/FileDownloader_curl.cpp
+}
 core_linux {
     CONFIG += use_external_download
 
