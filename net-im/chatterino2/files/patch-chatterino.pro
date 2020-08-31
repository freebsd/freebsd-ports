--- chatterino.pro.orig	2020-08-31 14:42:30 UTC
+++ chatterino.pro
@@ -82,7 +82,9 @@ include(lib/settings.pri)
 include(lib/serialize.pri)
 include(lib/winsdk.pri)
 include(lib/rapidjson.pri)
+!freebsd {
 include(lib/qtkeychain.pri)
+}
 
 exists( $$OUT_PWD/conanbuildinfo.pri ) {
     message("Using conan packages")
