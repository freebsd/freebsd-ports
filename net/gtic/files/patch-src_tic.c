--- src/tic.c.orig	Mon Jul  6 15:39:46 1998
+++ src/tic.c	Sun Sep 12 15:38:14 1999
@@ -227,7 +227,7 @@
     else if(!strcasecmp(buff,"ReceiptRequest")) continue; /* skip by FSC-0087 */
     else
     {
-      e_printf("readtic: %s(%d) - %s[%s] - keyword unknown - ignored",
+      l_printf("readtic: %s(%d) - %s[%s] - keyword unknown - ignored",
       	tlist->name,linecnt,buff,v);
       continue;
     }
