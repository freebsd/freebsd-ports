--- RTjpegN.c.orig	Mon Jul  2 23:55:42 2001
+++ RTjpegN.c	Thu Aug  5 00:03:22 2004
@@ -351,8 +351,8 @@
   case 0x00:
     data[i]= 0;
     break;
-  default: 
-	
+  default:
+    break; 
   } 
 
   if( bitoff == 0 ) {
