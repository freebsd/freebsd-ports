--- src/dc_com.h	Sat Oct 20 03:32:19 2001
+++ src/dc_com.h	Sun Dec  2 19:34:12 2001
@@ -21,6 +21,8 @@
 #ifndef __DC_COM_H__
 #define __DC_COM_H__
 
+#include <time.h>
+
 extern char last_cmd[5120];       /* contains the first string of the last send_dc_line call */ 
                                   /* mainly used for debug features.                         */
 
