--- bsd/cpumeter.cc.orig	Tue Oct 28 17:42:56 2003
+++ bsd/cpumeter.cc	Tue Oct 28 17:43:20 2003
@@ -123,12 +123,12 @@
     static int firstTime = 1;
     if (firstTime) {
       fprintf(stderr,
-"  Warning:  the CPU tick counters are not changing.  This could
-be due to running a kernel besides /netbsd (or the equivalent for FreeBSD).
-  If this is the case, re-run xosview with the -N kernel-name option.
-  If not, then this is a bug.  Please send a message to
-bgrayson@ece.utexas.edu, in addition to any send-pr bug reports
-(or in lieu of -- it ought to get fixed faster if you contact me
+"  Warning:  the CPU tick counters are not changing.  This could \
+be due to running a kernel besides /netbsd (or the equivalent for FreeBSD). \
+  If this is the case, re-run xosview with the -N kernel-name option. \
+  If not, then this is a bug.  Please send a message to \
+bgrayson@ece.utexas.edu, in addition to any send-pr bug reports \
+(or in lieu of -- it ought to get fixed faster if you contact me \
 directly).  Thanks!\n");
       firstTime = 0;
     }
