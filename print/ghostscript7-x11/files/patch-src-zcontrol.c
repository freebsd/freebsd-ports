--- src/zcontrol.c.orig	2013-04-30 11:09:59.000000000 +0900
+++ src/zcontrol.c	2013-04-30 11:11:03.000000000 +0900
@@ -356,7 +356,7 @@
 {
     os_ptr op = osp;
     register es_ptr ep = esp;
-    long var = ep[-3].value.intval;
+    int var = ep[-3].value.intval;
 
     if (var > ep[-1].value.intval) {
 	esp -= 5;		/* pop everything */
@@ -375,7 +375,7 @@
 {
     os_ptr op = osp;
     register es_ptr ep = esp;
-    long var = ep[-3].value.intval;
+    int var = ep[-3].value.intval;
 
     if (var < ep[-1].value.intval) {
 	esp -= 5;		/* pop everything */
