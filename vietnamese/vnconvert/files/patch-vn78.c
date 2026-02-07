--- vn78.c.orig	Fri May 20 13:36:15 1994
+++ vn78.c	Sun Mar 25 08:34:01 2001
@@ -959 +959 @@
-    for (n = sizeof(icode); n; n--) {
+    for (n = sizeof(icode) - 1; n >= 0; n--) {
@@ -1004 +1004 @@
-    for (n = sizeof(icode); n; n--) {
+    for (n = sizeof(icode) - 1; n >= 0; n--) {
