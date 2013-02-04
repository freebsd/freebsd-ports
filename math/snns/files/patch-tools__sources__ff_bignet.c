--- tools/sources/ff_bignet.c.orig	2008-04-21 16:56:07.000000000 +0900
+++ tools/sources/ff_bignet.c	2012-10-24 04:46:15.000000000 +0900
@@ -1009,7 +1009,7 @@
   UPDATE   : 
 ******************************************************************************/
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     char *file_name;
     int err;
