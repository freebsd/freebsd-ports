$NetBSD: patch-ad,v 1.4 1999/11/26 22:12:37 hubertf Exp $

diff -x *.orig -urN ./icb/helpdata.c /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/helpdata.c
--- ./icb/helpdata.c	Fri Feb 24 22:20:23 1995
+++ /usr/pkgsrc/net/icb/work.i386.unpatched/icb-5.0.9/icb/helpdata.c	Fri Nov 26 22:56:30 1999
@@ -600,6 +600,11 @@
 "    waiting for your screen, this gives you a chance to see the output",
 "    of your command.",
 "",
+"printtime       (boolean)               default: false",
+"",
+"    Print the current time in front of every line sent to the display",
+"    and log file.",
+"",
 "restricted      (boolean)               default: false",
 "",
 "    Restricted shuts off the ability to run subshell commands or to",
