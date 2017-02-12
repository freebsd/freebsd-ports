C++11 does not allow narrowing of integer types by default -- however multiple
constants defined in the code are too large to fit into a signed int, and rely
on the narrowing behaviour.

--- telegramqml.pro.orig	2017-02-11 13:02:31 UTC
+++ telegramqml.pro
@@ -31,6 +31,11 @@ linux {
     }
 }
 
+# Explictely allow narrowing of integer types
+clang {
+    QMAKE_CXXFLAGS += -Wno-c++11-narrowing
+}
+
 contains(BUILD_MODE,lib) {
     isEmpty(PREFIX) {
         isEmpty(INSTALL_HEADERS_PREFIX): INSTALL_HEADERS_PREFIX = $$[QT_INSTALL_HEADERS]
