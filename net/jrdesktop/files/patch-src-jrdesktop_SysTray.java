--- src/jrdesktop/SysTray.java.orig	2008-05-15 17:22:10.000000000 +0200
+++ src/jrdesktop/SysTray.java	2008-05-15 17:22:18.000000000 +0200
@@ -51,6 +51,11 @@
     }
     
     public static void displayViewer(String viewer, int size, boolean connected) {
+        if (!SystemTray.isSupported()) {
+            System.err.println("Tray unavailable");
+            return;
+        }
+
         if (connected) {
             trayIcon.displayMessage("Viewer details", viewer + " connected !!", 
                     TrayIcon.MessageType.INFO);
