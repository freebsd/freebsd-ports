--- src/smtp_in.c.orig	Wed Aug 15 13:09:12 2001
+++ src/smtp_in.c	Wed Nov 14 13:24:12 2001
@@ -2482,6 +2482,7 @@
             mail_from_size + 5000 : 0))
       {
       smtp_printf("452 space shortage, please try later\r\n");
+      sender_address = NULL;
       break;
       }
 
