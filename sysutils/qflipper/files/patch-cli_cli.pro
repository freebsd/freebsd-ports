--- cli/cli.pro.orig	2023-03-27 09:51:38 UTC
+++ cli/cli.pro
@@ -20,18 +20,18 @@ win32:!win32-g++ {
         $$OUT_PWD/../dfu/libdfu.a
 
     contains(CONFIG, static): PRE_TARGETDEPS += \
-        $$OUT_PWD/../plugins/libflipperproto0.a \
-        $$OUT_PWD/../3rdparty/lib3rdparty.a
+        $$OUT_PWD/../plugins/libflipperproto0.a
 }
 
 unix|win32 {
     LIBS += \
         -L$$OUT_PWD/../backend/ -lbackend \
-        -L$$OUT_PWD/../dfu/ -ldfu
+        -L$$OUT_PWD/../dfu/ -ldfu \
+        -lprotobuf-nanopb
 
     contains(CONFIG, static): LIBS += \
         -L$$OUT_PWD/../plugins/ -lflipperproto0 \
-        -L$$OUT_PWD/../3rdparty/ -l3rdparty
+        -lprotobuf-nanopb
 }
 
 win32 {
