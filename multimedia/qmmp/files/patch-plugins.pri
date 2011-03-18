--- src/plugins/plugins.pri	(revision 2054)
+++ src/plugins/plugins.pri	(working copy)
@@ -1,3 +1,4 @@
 include(../../qmmp.pri)
 unix:PLUGINS_PREFIX=../../../../lib/qmmp
 win32:PLUGINS_PREFIX=../../../../../bin/plugins
+INCLUDEPATH += ../../../qmmp
