--- src/qt/bitcoin.cpp.orig	2012-06-19 16:44:55.000000000 -0400
+++ src/qt/bitcoin.cpp	2012-09-03 13:30:43.641710746 -0400
@@ -134,7 +134,7 @@
 #ifndef BITCOIN_QT_TEST
 int main(int argc, char *argv[])
 {
-#if !defined(MAC_OSX) && !defined(WIN32)
+#if !defined(MAC_OSX) && !defined(WIN32) && !defined(__FreeBSD__)
 // TODO: implement qtipcserver.cpp for Mac and Windows
 
     // Do this early as we don't want to bother initializing if we are just calling IPC
@@ -261,7 +261,7 @@
                 // Place this here as guiref has to be defined if we dont want to lose URIs
                 ipcInit();
 
-#if !defined(MAC_OSX) && !defined(WIN32)
+#if !defined(MAC_OSX) && !defined(WIN32) && !defined(__FreeBSD__)
 // TODO: implement qtipcserver.cpp for Mac and Windows
 
                 // Check for URI in argv
