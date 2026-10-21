--- core/Common/Network/network.pro.orig	2026-10-11 14:54:04 UTC
+++ core/Common/Network/network.pro
@@ -56,6 +56,7 @@
 HEADERS += $$PWD/WebSocket/include/localipc.h
 SOURCES += $$PWD/WebSocket/src/localipc/localipc.cpp
 core_linux:LIBS += -lpthread   # asio/std::thread (idempotent if websocket also added it)
+core_freebsd:LIBS += -lpthread
 
 # DOWNLOAD/UPLOAD
 include(./FileTransporter/filetransporter.pri)
