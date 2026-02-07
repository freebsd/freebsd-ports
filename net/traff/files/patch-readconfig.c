--- readconfig.c.orig	2022-11-06 12:02:53 UTC
+++ readconfig.c
@@ -23,6 +23,8 @@
 
 #define WHITESPACE " \t\r\n"
 
+char conf_file[];
+
 typedef enum {
   //      oSQL,
       oBadOption,oDevices,oPeriod,oCat,
