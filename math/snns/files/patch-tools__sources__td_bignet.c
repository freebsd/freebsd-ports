--- tools/sources/td_bignet.c.orig	2008-04-21 16:56:09.000000000 +0900
+++ tools/sources/td_bignet.c	2012-10-24 04:46:24.000000000 +0900
@@ -1052,7 +1052,7 @@
 
   UPDATE   : 
 ******************************************************************************/
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     char *file_name;
     int err;
