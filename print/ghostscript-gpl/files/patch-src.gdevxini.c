Message-ID: <3AB64C01.54380C00@we.lc.ehu.es>
Date: Mon, 19 Mar 2001 19:12:17 +0100
From: "Jose M. Alcaide" <jose@we.lc.ehu.es>
Organization: Universidad del Pais Vasco - Dpto. de Electricidad y Electronica
Subject: new patch for ghostscript 6.50

Hello Andreas,

About a month ago I sent you a patch for GhostScript 6.50. Without that
patch, LyX 1.1.6 cannot show included EPS figures. Now that the LyX
port has been updated this problem will begin to hit many LyX users,
and the ports freeze is coming soon...

The problem is described in:

http://sourceforge.net/bugs/?func=detailbug&bug_id=124957&group_id=1897

I am resending the patch attached to this message. I am using Ghostscript
with this patch applied and everything (including LyX) seems to work OK.

Cheers,
-- JMA
****** Jose M. Alcaide  //  jose@we.lc.ehu.es  //  jmas@FreeBSD.org ******
** "Beware of Programmers who carry screwdrivers" --  Leonard Brandwein **
--------------8E7698D95DE1CB06D5711335
Content-Type: text/plain; charset=us-ascii;
 name="patch-src,gdevxini.c"
Content-Transfer-Encoding: 7bit
Content-Disposition: inline;
 filename="patch-src,gdevxini.c"

--- src/gdevxini.c.orig	Tue Sep 19 21:00:23 2000
+++ src/gdevxini.c	Tue Feb 20 18:07:09 2001
@@ -654,8 +654,10 @@
     }
     x_set_buffer(xdev);
     /* Clear the destination pixmap to avoid initializing with garbage. */
-    xdev->dest = (xdev->bpixmap != (Pixmap) 0 ?
+    if (xdev->dest == (Pixmap) 0) {
+    	xdev->dest = (xdev->bpixmap != (Pixmap) 0 ?
 		  xdev->bpixmap : (Pixmap) xdev->win);
+    }
     if (xdev->dest != (Pixmap) 0) {
 	XSetForeground(xdev->dpy, xdev->gc, xdev->background);
 	XFillRectangle(xdev->dpy, xdev->dest, xdev->gc,


