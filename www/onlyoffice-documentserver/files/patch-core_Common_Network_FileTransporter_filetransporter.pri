--- core/Common/Network/FileTransporter/filetransporter.pri.orig	2022-01-19 14:24:12 UTC
+++ core/Common/Network/FileTransporter/filetransporter.pri
@@ -19,6 +19,12 @@ core_mac:CONFIG += use_external_transport
 
 use_external_transport:DEFINES += USE_EXTERNAL_TRANSPORT
 
+core_freebsd {
+    !use_external_transport:include($$PWD/../../3dParty/curl/curl.pri)
+    LIBS += -lcurl
+    SOURCES += $$PWD/src/FileTransporter_curl.cpp
+}
+
 core_linux {
     !use_external_transport:include($$PWD/../../3dParty/curl/curl.pri)
     SOURCES += $$PWD/src/FileTransporter_curl.cpp
