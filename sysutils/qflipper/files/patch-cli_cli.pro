--- cli/cli.pro.orig	2022-11-27 06:21:50 UTC
+++ cli/cli.pro
@@ -11,13 +11,13 @@ unix|win32 {
 
 unix|win32 {
     LIBS += \
-        -L$$OUT_PWD/../3rdparty/ -l3rdparty \
+        -lprotobuf-nanopb \
         -L$$OUT_PWD/../plugins/ -lflipperproto0 \
         -L$$OUT_PWD/../backend/ -lbackend \
         -L$$OUT_PWD/../dfu/ -ldfu
 
     contains(CONFIG, static): LIBS += \
-        -L$$OUT_PWD/../3rdparty/ -l3rdparty \
+        -lprotobuf-nanopb \
         -L$$OUT_PWD/../plugins/ -lflipperproto0
 }
 
