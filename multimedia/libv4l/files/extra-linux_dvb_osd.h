--- ../linux/dvb/osd.h.bak	2014-12-01 10:58:18.000000000 +0100
+++ ../linux/dvb/osd.h	2015-01-24 00:12:54.252160592 +0100
@@ -24,7 +24,7 @@
 #ifndef _DVBOSD_H_
 #define _DVBOSD_H_
 
-#include <linux/compiler.h>
+#include <sys/types.h>
 
 typedef enum {
   // All functions return -2 on "not open"
