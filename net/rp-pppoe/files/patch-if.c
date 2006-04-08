--- if.c.orig	Thu Apr  6 01:14:48 2006
+++ if.c	Thu Apr  6 01:14:58 2006
@@ -99,7 +99,7 @@
 
 static unsigned char *bpfBuffer;	/* Packet filter buffer */
 static int bpfLength = 0;		/* Packet filter buffer length */
-static int bpfSize = 0;		        /* Number of unread bytes in buffer */
+       int bpfSize = 0;		        /* Number of unread bytes in buffer */
 static int bpfOffset = 0;		/* Current offset in bpfBuffer */
 #endif
 
