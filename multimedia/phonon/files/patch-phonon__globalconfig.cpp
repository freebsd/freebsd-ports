--- ./phonon/globalconfig.cpp.orig	2011-09-09 13:27:00.943109464 +0200
+++ ./phonon/globalconfig.cpp	2011-09-09 15:22:15.732984584 +0200
@@ -35,6 +35,8 @@
 #include <QtCore/QList>
 #include <QtCore/QVariant>
 
+#define QT_NO_PHONON_PLATFORMPLUGIN
+
 QT_BEGIN_NAMESPACE
 
 namespace Phonon
