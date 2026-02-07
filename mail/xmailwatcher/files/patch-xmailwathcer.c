--- xmailwatcher.c.orig	Wed May 30 21:18:27 2007
+++ xmailwatcher.c	Wed May 30 21:19:23 2007
@@ -149,7 +149,7 @@
 void timedRescan();
 void listEvent();
 void iconEvent();
-void iconCallback();
+static void iconCallback(Widget w, XtPointer client_data, XtPointer call_data);
 
 static int mapped;
 
