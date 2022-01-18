--- core/X2tConverter/build/Qt/X2tConverter.pri.orig	2021-09-30 12:13:32 UTC
+++ core/X2tConverter/build/Qt/X2tConverter.pri
@@ -103,5 +103,8 @@ include($$PWD/../../../Common/3dParty/boost/boost.pri)
 core_windows {
     LIBS += -lAdvapi32
 }
+core_freebsd {
+    LIBS += -liconv
+}
 ########################################################
 
