--- systems/freebsd/logcheck.sh.dist	Mon Nov  1 00:07:29 1999
+++ systems/freebsd/logcheck.sh	Mon Sep  8 06:56:37 2003
@@ -173,6 +173,7 @@
 # FreeBSD 2.x
 $LOGTAIL /var/log/messages > $TMPDIR/check.$$
 $LOGTAIL /var/log/maillog >> $TMPDIR/check.$$
+$LOGTAIL /var/log/security >> $TMPDIR/check.$$
 
 # BSDI 2.x
 #$LOGTAIL /var/log/messages > $TMPDIR/check.$$
