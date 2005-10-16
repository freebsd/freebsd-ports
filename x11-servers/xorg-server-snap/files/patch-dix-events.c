Index: programs/Xserver/dix/events.c
===================================================================
RCS file: /cvs/xorg/xc/programs/Xserver/dix/events.c,v
retrieving revision 1.16
retrieving revision 1.17
diff -u -u -r1.16 -r1.17
--- programs/Xserver/dix/events.c	15 Jul 2005 05:48:29 -0000	1.16
+++ programs/Xserver/dix/events.c	25 Aug 2005 22:11:04 -0000	1.17
@@ -1,4 +1,4 @@
-/* $XdotOrg: xc/programs/Xserver/dix/events.c,v 1.16 2005/07/15 05:48:29 kem Exp $ */
+/* $XdotOrg: xc/programs/Xserver/dix/events.c,v 1.17 2005/08/25 22:11:04 anholt Exp $ */
 /* $XFree86: xc/programs/Xserver/dix/events.c,v 3.51 2004/01/12 17:04:52 tsi Exp $ */
 /************************************************************
 
@@ -675,7 +675,9 @@
 		(sprite.current->bits->yhot != cursor->bits->yhot))
 	    XineramaCheckPhysLimits(cursor, FALSE);
     	(*sprite.screen->DisplayCursor)(sprite.screen, cursor);
+	FreeCursor(sprite.current, (Cursor)0);
 	sprite.current = cursor;
+	sprite.current->refcnt++;
     }
 }
 
@@ -930,7 +932,9 @@
 			    (ScreenPtr)NULL);
 	(*sprite.hotPhys.pScreen->DisplayCursor) (sprite.hotPhys.pScreen,
 						  cursor);
+	FreeCursor(sprite.current, (Cursor)0);
 	sprite.current = cursor;
+	sprite.current->refcnt++;
     }
 }
 
@@ -2184,6 +2188,7 @@
 #endif
     sprite.win = win;
     sprite.current = wCursor (win);
+    sprite.current->refcnt++;
     spriteTraceGood = 1;
     ROOT = win;
     (*pScreen->CursorLimits) (
