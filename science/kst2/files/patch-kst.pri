--- ./kst.pri.orig	2010-08-10 11:48:14.000000000 +0400
+++ ./kst.pri	2010-08-23 20:35:48.741714646 +0400
@@ -23,7 +23,6 @@
 QT += core xml
 
 CONFIG += warn_on
-!win32:CONFIG += silent
 
 DEBUG_MODE = $$(KST_DEBUG_MODE)
 contains(DEBUG_MODE, 1) {
