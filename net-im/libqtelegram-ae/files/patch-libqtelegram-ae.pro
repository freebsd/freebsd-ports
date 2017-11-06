C++11 does not allow narrowing of integer types by default -- however multiple
constants defined in the code are too large to fit into a signed int, and rely
on the narrowing behaviour.

--- libqtelegram-ae.pro.orig	2017-02-10 23:08:39 UTC
+++ libqtelegram-ae.pro
@@ -25,6 +25,11 @@ linux {
     }
 }
 
+# Explictely allow narrowing of integer types
+clang {
+   QMAKE_CXXFLAGS += -Wno-c++11-narrowing
+}
+
 !contains(CONFIG, no_install) {
     isEmpty(PREFIX) {
         isEmpty(INSTALL_HEADERS_PREFIX): INSTALL_HEADERS_PREFIX = $$[QT_INSTALL_HEADERS]
