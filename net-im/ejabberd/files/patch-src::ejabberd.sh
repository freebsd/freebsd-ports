--- ejabberd.sh	Thu Jan  1 03:00:00 1970
+++ ejabberd.sh	Sat Jul  3 16:49:51 2004
@@ -0,0 +1,42 @@
+#! /bin/sh
+#
+# ejabberd        Start/stop ejabberd server
+#
+#
+
+PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/bin:/usr/local/sbin
+EJABBERD=%%PREFIX%%/bin/ejabberd
+EJABBERDCTL=%%PREFIX%%/bin/ejabberdctl
+EJABBERDUSER=ejabberd
+NAME=ejabberd
+DESC=ejabberd
+
+test -f $EJABBERD || exit 0
+test -f $EJABBERDCTL || exit 0
+
+set -e
+
+case "$1" in
+    start)
+	echo -n "Starting $DESC: "
+	su ejabberd -c "$EJABBERD -heart -noshell -detached"
+	echo "$NAME."
+	;;
+    stop)
+	echo -n "Stopping $DESC: "
+	su ejabberd -c "$EJABBERDCTL stop"
+	echo "$NAME."
+	;;
+    restart|force-reload)
+	echo -n "Restarting $DESC: "
+	su ejabberd -c "$EJABBERDCTL restart"
+	echo "$NAME."
+	;;
+    *)
+	N=/etc/init.d/$NAME
+	echo "Usage: $N {start|stop|restart|force-reload}" >&2
+	exit 1
+	;;
+esac
+
+exit 0
