--- src/crc.c.orig	1993-03-25 08:31:42.000000000 -0800
+++ src/crc.c	2013-09-18 00:52:27.281917756 -0700
@@ -237,7 +237,7 @@
    /* quietly ignore files we can't stat */
 
    if (name != NULL && stat(name, &stat_buf) != 0)
-      return;
+      return 0;
 
    /* don't do a crc on strange files */
 
