--- xcdrdata.h.orig	Fri May 17 16:40:55 2002
+++ xcdrdata.h	Fri May 17 16:40:30 2002
@@ -3,6 +3,7 @@
 */
 
 #include <time.h>
+#include <sys/types.h>
 
 typedef struct setup_data {
 	gint writer_devnr;
