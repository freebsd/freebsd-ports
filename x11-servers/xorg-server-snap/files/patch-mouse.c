--- programs/Xserver/hw/xfree86/input/mouse/mouse.c.orig	Sat Jan 29 06:57:55 2005
+++ programs/Xserver/hw/xfree86/input/mouse/mouse.c	Sat Jan 29 06:59:03 2005
@@ -1501,8 +1501,8 @@
 
 	case PROT_SYSMOUSE:	/* sysmouse */
 	    buttons = (~pBuf[0]) & 0x07;
-	    dx =    (char)(pBuf[1]) + (char)(pBuf[3]);
-	    dy = - ((char)(pBuf[2]) + (char)(pBuf[4]));
+	    dx =    (signed char)(pBuf[1]) + (signed char)(pBuf[3]);
+	    dy = - ((signed char)(pBuf[2]) + (signed char)(pBuf[4]));
 	    /* FreeBSD sysmouse sends additional data bytes */
 	    if (pMse->protoPara[4] >= 8) {
 		/*
