--- libretroshare/src/rsserver/rsloginhandler.cc.orig	2012-01-15 04:44:59.000000000 +0100
+++ libretroshare/src/rsserver/rsloginhandler.cc	2012-01-15 04:43:08.000000000 +0100
@@ -4,6 +4,7 @@
 #include <pqi/authgpg.h>
 #include "rsloginhandler.h"
 #include "util/rsdir.h"
+#include "rsinit.h"
 
 #ifdef UBUNTU
 #include <gnome-keyring-1/gnome-keyring.h>
@@ -196,7 +197,7 @@
 	/******************** OSX KeyChain stuff *****************************/
 #else /* UNIX, but not UBUNTU or APPLE */
 
-	FILE* helpFile = RsDirUtil::rs_fopen(getAutologinFileName.c_str(), "r");
+	FILE* helpFile = RsDirUtil::rs_fopen(getAutologinFileName(ssl_id).c_str(), "r");
 
 	if(helpFile == NULL){
 		std::cerr << "\nFailed to open help file\n" << std::endl;
@@ -408,7 +409,7 @@
 #else
 
 	/* WARNING: Autologin is inherently unsafe */
-	FILE* helpFile = RsDirUtil::rs_fopen(getAutologinFileName.c_str(), "w");
+	FILE* helpFile = RsDirUtil::rs_fopen(getAutologinFileName(ssl_id).c_str(), "w");
 
 	if(helpFile == NULL){
 		std::cerr << "\nRsStoreAutoLogin(): Failed to open help file\n" << std::endl;
