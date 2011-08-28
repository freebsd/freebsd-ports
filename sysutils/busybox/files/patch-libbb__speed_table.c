--- ./libbb/speed_table.c.orig	2011-08-11 02:23:58.000000000 +0200
+++ ./libbb/speed_table.c	2011-08-28 13:00:03.000000000 +0200
@@ -10,7 +10,7 @@
 #include "libbb.h"
 
 struct speed_map {
-	unsigned short speed;
+	unsigned int speed;
 	unsigned short value;
 };
 
