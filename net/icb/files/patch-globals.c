$NetBSD: patch-ac,v 1.3 1999/11/26 22:12:37 hubertf Exp $

diff -x *.orig -urN ./icb/globals.c /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/globals.c
--- ./icb/globals.c	Fri Feb 24 22:20:22 1995
+++ /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/globals.c	Fri Nov 26 22:56:30 1999
@@ -59,6 +59,7 @@
 	1,		/* beeps */
 	"vi",		/* editmode */
 	0,		/* tabreply */
+	0,		/* printtime */
 	1, 		/* cute */
 	0,		/* autodel */
 	"",		/* personalto */
