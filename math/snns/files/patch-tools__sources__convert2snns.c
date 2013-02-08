--- tools/sources/convert2snns.c.orig	2008-04-21 16:56:07.000000000 +0900
+++ tools/sources/convert2snns.c	2012-10-24 04:45:56.000000000 +0900
@@ -390,7 +390,7 @@
   UPDATE   : june 15 1993
 ******************************************************************************/
 
-void main(int argc,char **argv)
+int main(int argc,char **argv)
 {
 FILE *fp;
 
