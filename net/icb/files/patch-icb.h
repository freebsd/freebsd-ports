$NetBSD: patch-ae,v 1.3 1999/11/26 22:12:37 hubertf Exp $

diff -x *.orig -urN ./icb/icb.h /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/icb.h
--- ./icb/icb.h	Fri Feb 24 22:20:23 1995
+++ /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/icb.h	Fri Nov 26 22:56:30 1999
@@ -38,6 +38,7 @@
 	int beeps;		/* whether beeps are audible */
 	char *editmode;		/* input editing mode */
 	int tabreply;		/* should replies go into the tab history? */
+	int printtime;		/* print timestamp in front of every msg? */
 	int cute;		/* cute messages when a blank line is entered */
 	int autodel;		/* automatically delete nicks from the tab
 			        history that produce a "not logged on" error */
