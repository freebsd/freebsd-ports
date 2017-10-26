--- areacode/actest.c.orig	1997-02-16 11:22:50.000000000 +0000
+++ areacode/actest.c	2017-10-17 18:26:38.899231000 +0000
@@ -60,7 +60,8 @@
 
         printf ("Enter phone number: ");
         fflush (stdout);
-        gets (Buf);
+        fgets (Buf, sizeof(Buf), stdin);
+        Buf[strcspn (Buf, "\n")] = '\0';
         if (strlen (Buf) == 0) {
             break;
         }
