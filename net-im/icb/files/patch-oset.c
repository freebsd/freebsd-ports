$NetBSD: patch-af,v 1.2 1999/11/26 22:12:37 hubertf Exp $

diff -x *.orig -urN ./icb/oset.c /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/oset.c
--- ./icb/oset.c	Fri Feb 24 22:20:24 1995
+++ /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/oset.c	Fri Nov 26 22:56:31 1999
@@ -39,6 +39,7 @@
 	{ "pagesize",	V_INT,		(char *)&gv.pagesize },
 	{ "pauseonshell",	V_BOOLEAN,	(char *)&gv.pauseonshell },
 	{ "personalto", V_STRING,	(char *)&gv.personalto },
+	{ "printtime",	V_BOOLEAN,	(char *)&gv.printtime },
 	{ "restricted",	V_BOOLEAN,	(char *)&gv.restricted },
 	{ "tabreply",	V_BOOLEAN,	(char *)&gv.tabreply },
 	{ "timedisplay",	V_STRING,	(char *)&gv.timedisplay },
