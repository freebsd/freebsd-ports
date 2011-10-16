--- ./policykitlistener.cpp.orig	2011-08-10 09:25:19.903011898 +0200
+++ ./policykitlistener.cpp	2011-08-10 09:27:15.332896437 +0200
@@ -22,6 +22,7 @@
 #include "AuthDialog.h"
 
 #include <KDebug>
+#include <KWindowSystem>
 
 #include <PolkitQt1/Agent/Listener>
 #include <PolkitQt1/Agent/Session>
@@ -100,6 +101,7 @@
     kDebug() << "WinId of the dialog is " << m_dialog.data()->winId() << m_dialog.data()->effectiveWinId();
     m_dialog.data()->setOptions();
     m_dialog.data()->show();
+    KWindowSystem::forceActiveWindow(m_dialog.data()->winId());
     kDebug() << "WinId of the shown dialog is " << m_dialog.data()->winId() << m_dialog.data()->effectiveWinId();
 
     m_numTries = 0;
