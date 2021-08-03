--- pan/tasks/socket-impl-main.cc.orig	2021-08-03 02:06:37 UTC
+++ pan/tasks/socket-impl-main.cc
@@ -30,10 +30,7 @@
 //#include <glib/giochannel.h>
 //#include <glib/gstring.h>
 
-extern "C"
-{
-  #include <glib.h>
-}
+#include <glib.h>
 
 #include <pan/tasks/socket.h>
 
