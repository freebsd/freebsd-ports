Index: programs/Xserver/Xext/saver.c
===================================================================
RCS file: /cvs/xc/programs/Xserver/Xext/saver.c,v
retrieving revision 3.8
retrieving revision 3.8.2.1
diff -u -u -r3.8 -r3.8.2.1
--- programs/Xserver/Xext/saver.c	17 Nov 2003 22:20:26 -0000	3.8
+++ programs/Xserver/Xext/saver.c	2 Mar 2004 19:39:48 -0000	3.8.2.1
@@ -27,7 +27,7 @@
  * Author:  Keith Packard, MIT X Consortium
  */
 
-/* $XFree86: xc/programs/Xserver/Xext/saver.c,v 3.8 2003/11/17 22:20:26 dawes Exp $ */
+/* $XFree86: xc/programs/Xserver/Xext/saver.c,v 3.8.2.1 2004/03/02 19:39:48 dawes Exp $ */
 
 #define NEED_REPLIES
 #define NEED_EVENTS
@@ -810,7 +810,7 @@
     DepthPtr			pDepth;
     WindowOptPtr		ancwopt;
     unsigned long		*pVlist;
-    unsigned long		*values = 0;
+    unsigned long		*values = 0, *save = 0;
     unsigned long		tmask, imask;
     unsigned long		val;
     Pixmap			pixID;
@@ -938,6 +938,7 @@
 	ret = BadAlloc;
 	goto bail;
     }
+    save = values;
     pAttr->screen = pScreen;
     pAttr->client = client;
     pAttr->x = stuff->x;
@@ -1166,7 +1167,7 @@
 bail:
     CheckScreenPrivate (pScreen);
     xfree (pAttr);
-    xfree (values);
+    xfree (save);
     return ret;
 }
 
