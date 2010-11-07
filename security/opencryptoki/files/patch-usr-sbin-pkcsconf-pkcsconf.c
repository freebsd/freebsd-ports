--- usr/sbin/pkcsconf/pkcsconf.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/sbin/pkcsconf/pkcsconf.c	2010-10-20 00:47:46.462984231 +0900
@@ -654,6 +654,8 @@
       free (newpin2);
    }
 
+   cleanup();
+
    return rc;
 
 }
