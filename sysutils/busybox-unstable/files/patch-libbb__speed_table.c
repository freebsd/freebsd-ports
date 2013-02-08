--- ./libbb/speed_table.c.orig	2012-06-26 13:35:45.000000000 +0000
+++ ./libbb/speed_table.c	2012-07-17 02:08:37.000000000 +0000
@@ -10,7 +10,7 @@
 #include "libbb.h"
 
 struct speed_map {
-	unsigned short speed;
+	unsigned int speed;
 	unsigned short value;
 };
 
