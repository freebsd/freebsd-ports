--- cmdline.c.orig	Mon Jun 16 18:05:02 2003
+++ cmdline.c	Sat Jul 26 02:30:59 2003
@@ -167,7 +167,7 @@
     					break;
 					}
 					if(*pointer=='?'){
-						gets(buffer);
+						fgets(buffer,sizeof(buffer),stdin);
 						template[template_number++]=buffer;
 						buffer+=strlen(buffer);
 						pointer+=strlen(pointer)-1;
