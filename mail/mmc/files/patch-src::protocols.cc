--- src/protocols.cc.orig	Sat Jan 20 00:19:56 2001
+++ src/protocols.cc	Sat Nov  8 02:07:44 2003
@@ -46,6 +46,8 @@
 #include "progress.h"
 #include "pop3.h"
 
+using namespace std;
+
 // TODO: make the following List User-Configurable
 gchar const * headers[] = {
 				"From:",
