--- rdp/rdpview.cpp.orig	2014-03-27 03:42:11.000000000 -0400
+++ rdp/rdpview.cpp	2014-04-08 10:37:18.607309053 -0400
@@ -158,36 +158,36 @@
         width = this->parentWidget()->size().width();
         height = this->parentWidget()->size().height();
     }
-    arguments << "-g" << QString::number(width) + 'x' + QString::number(height);
+    arguments << "/size:" + QString::number(width) + 'x' + QString::number(height);
 
-    arguments << "-k" << keymapToXfreerdp(m_hostPreferences->keyboardLayout());
+    arguments << "/kbd:" + keymapToXfreerdp(m_hostPreferences->keyboardLayout());
 
     if (!m_url.userName().isEmpty()) {
         // if username contains a domain, it needs to be set with another parameter
         if (m_url.userName().contains('\\')) {
             const QStringList splittedName = m_url.userName().split('\\');
-            arguments << "-d" << splittedName.at(0);
-            arguments << "-u" << splittedName.at(1);
+            arguments << "/d:" + splittedName.at(0);
+            arguments << "/u:" + splittedName.at(1);
         } else {
-            arguments << "-u" << m_url.userName();
+            arguments << "/u:" + m_url.userName();
         }
     } else {
-        arguments << "-u" << "";
+        arguments << "/u:";
     }
 
     if (!m_url.password().isNull())
-        arguments << "-p" << m_url.password();
+        arguments << "/p:" + m_url.password();
 
-    arguments << "-D";  // request the window has no decorations
-    arguments << "-X" << QString::number(m_container->winId());
-    arguments << "-a" << QString::number((m_hostPreferences->colorDepth() + 1) * 8);
+    arguments << "-decorations";  // request the window has no decorations
+    arguments << "/parent-window:" + QString::number(m_container->winId());
+    arguments << "/bpp:" + QString::number((m_hostPreferences->colorDepth() + 1) * 8);
 
     switch (m_hostPreferences->sound()) {
     case 1:
-        arguments << "-o";
+        arguments << "/audio-mode";
         break;
     case 0:
-        arguments << "--plugin" << "rdpsnd";
+        arguments << "/multimedia:sys:alsa";
         break;
     case 2:
     default:
@@ -195,34 +195,29 @@
     }
 
     if (!m_hostPreferences->shareMedia().isEmpty()) {
-        QStringList shareMedia;
-        shareMedia << "--plugin" << "rdpdr" << "--data" << "disk:media:" + m_hostPreferences->shareMedia() << "--";
-        arguments += shareMedia;
+        arguments << "/drive:media," + m_hostPreferences->shareMedia();
     }
 
-    QString performance;
     switch (m_hostPreferences->performance()) {
     case 0:
-        performance = 'm';
+        arguments << "/network modem";
         break;
     case 1:
-        performance = 'b';
+        arguments << "/network broadband";
         break;
     case 2:
-        performance = 'l';
+        arguments << "/network broadband";
         break;
     default:
         break;
     }
 
-    arguments << "-x" << performance;
-
     if (m_hostPreferences->console()) {
-        arguments << "-0";
+        arguments << "/admin Admin";
     }
 
     if (m_hostPreferences->remoteFX()) {
-        arguments << "--rfx";
+        arguments << "/rfx";
     }
 
     if (!m_hostPreferences->extraOptions().isEmpty()) {
@@ -233,13 +228,13 @@
     // krdc has no support for certificate management yet; it would not be possbile to connect to any host:
     // "The host key for example.com has changed" ...
     // "Add correct host key in ~/.freerdp/known_hosts to get rid of this message."
-    arguments << "--ignore-certificate";
+    arguments << "/cert-ignore";
 
     // clipboard sharing is activated in KRDC; user can disable it at runtime
-    arguments << "--plugin" << "cliprdr";
+    arguments << "+clipboard";
 
-    arguments << "-t" << QString::number(m_port);
-    arguments << m_host;
+    arguments << "/port:" + QString::number(m_port);
+    arguments << "/v:" + m_host;
 
     kDebug(5012) << "Starting xfreerdp with arguments:" << arguments;
 
