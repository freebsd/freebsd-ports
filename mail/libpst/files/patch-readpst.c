--- readpst.c.orig	Sun Sep 25 14:24:59 2005
+++ readpst.c	Sun Sep 25 14:25:19 2005
@@ -144,7 +144,7 @@
   int base64_body = 0;
   //  int encrypt = 0;
   FILE *fp;
-  char *enc; // base64 encoded attachment
+  char *enc = NULL; // base64 encoded attachment
   char *boundary = NULL, *b1, *b2; // the boundary marker between multipart sections
   char *temp = NULL; //temporary char pointer
   int attach_num = 0;
