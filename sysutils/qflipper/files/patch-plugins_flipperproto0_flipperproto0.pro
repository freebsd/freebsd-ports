--- plugins/flipperproto0/flipperproto0.pro.orig	2022-10-03 15:15:41 UTC
+++ plugins/flipperproto0/flipperproto0.pro
@@ -13,7 +13,6 @@ INCLUDEPATH += $$PWD/../protobufinterface \
 VERSION = 0.0.0
 
 INCLUDEPATH += $$PWD/../protobufinterface \
-    $$PWD/../../3rdparty/nanopb
 
 HEADERS += \
     guirequest.h \
@@ -59,13 +58,13 @@ unix|win32 {
     systemresponse.cpp
 
 unix|win32 {
-    LIBS += -L$$OUT_PWD/../../3rdparty/ -l3rdparty
+    LIBS += -lprotobuf-nanopb
 }
 
 DEFINES += PB_ENABLE_MALLOC
 
 unix:!macx {
-    target.path = $$PREFIX/lib/$$NAME/plugins
+    target.path = $$PREFIX/lib/qt5/plugins
 } else:macx {
     target.path = $$DESTDIR/../$${NAME}.app/Contents/PlugIns
 } else:win32 {
