--- src/jrdesktop/SysTray.java.orig	2008-05-08 17:04:24.000000000 +0200
+++ src/jrdesktop/SysTray.java	2008-05-08 17:04:56.000000000 +0200
@@ -51,6 +51,7 @@
     }
     
     public static void displayMsg(String Title, String Msg) {
+        if (!SystemTray.isSupported()) return;
         trayIcon.displayMessage(Title, Msg, TrayIcon.MessageType.INFO);
     }
     
