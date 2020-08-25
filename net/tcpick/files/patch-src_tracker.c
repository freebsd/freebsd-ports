--- src/tracker.c.orig	2020-08-25 17:17:55 UTC
+++ src/tracker.c
@@ -28,8 +28,7 @@
 #include "tcpick.h"
 #include "extern.h"
 
-struct CONN * first_conn = NULL; /*all connections, ends on a 0*/
-struct CONN * last_conn  = NULL; 
+
 
 int 
 status_switch(struct CONN * prev, enum STATUS status) 
