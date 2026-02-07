--- retroshare.pri.orig	2018-03-13 19:25:38 UTC
+++ retroshare.pri
@@ -16,7 +16,7 @@ no_retroshare_nogui:CONFIG -= retroshare
 
 # To enable RetroShare plugins append the following
 # assignation to qmake command line "CONFIG+=retroshare_plugins"
-CONFIG *= no_retroshare_plugins
+CONFIG *=retroshare_plugins
 retroshare_plugins:CONFIG -= no_retroshare_plugins
 
 # To enable RetroShare-android-service append the following assignation to
@@ -101,8 +101,8 @@ rs_macos10.10:CONFIG -= rs_macos10.11
 rs_macos10.12:CONFIG -= rs_macos10.11
 
 
-linux-* {
-	isEmpty(PREFIX)   { PREFIX   = "/usr" }
+freebsd-* {
+	isEmpty(PREFIX)   { PREFIX   = "/usr/local" }
 	isEmpty(BIN_DIR)  { BIN_DIR  = "$${PREFIX}/bin" }
 	isEmpty(INC_DIR)  { INC_DIR  = "$${PREFIX}/include/retroshare" }
 	isEmpty(LIB_DIR)  { LIB_DIR  = "$${PREFIX}/lib" }
