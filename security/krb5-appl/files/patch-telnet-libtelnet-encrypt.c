--- telnet/libtelnet/encrypt.c.orig	2009-11-05 12:15:06.000000000 -0800
+++ telnet/libtelnet/encrypt.c	2011-12-26 12:59:08.261571642 -0800
@@ -757,6 +757,9 @@
 	int dir = kp->dir;
 	register int ret = 0;
 
+	if (len > MAXKEYLEN)
+		len = MAXKEYLEN;
+
 	if (!(ep = (*kp->getcrypt)(*kp->modep))) {
 		if (len == 0)
 			return;
