--- src/dc_com.h.orig	Wed Nov 21 22:15:21 2001
+++ src/dc_com.h	Wed Nov 21 22:15:32 2001
@@ -21,6 +21,8 @@
 #ifndef __DC_COM_H__
 #define __DC_COM_H__
 
+#include <time.h>
+
 extern char last_cmd[5120];       /* contains the first string of the last send_dc_line call */ 
                                   /* mainly used for debug features.                         */
 
