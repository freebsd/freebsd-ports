--- jit/jit.sh.orig	Tue Jul 20 17:09:59 2004
+++ jit/jit.sh	Tue Jul 20 17:10:47 2004
@@ -0,0 +1,13 @@
+#!/bin/sh
+
+PREFIX=%%PREFIX%%
+USER="jabber"
+
+echo -n " jit"
+case ${1:-start} in
+start)
+    su -f -m ${USER} -c "$PREFIX/sbin/jit -c $PREFIX/etc/jabber-icq.xml -d " ;;
+
+stop)
+    killall -SIGKILL -u ${USER} jit;
+esac
