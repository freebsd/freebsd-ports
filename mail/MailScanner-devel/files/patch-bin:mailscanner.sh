--- ../MailScanner-4.22-5.old/bin/mailscanner.sh	Thu Jan  1 01:00:00 1970
+++ bin/mailscanner.sh	Mon Aug 11 12:36:06 2003
@@ -0,0 +1,55 @@
+#!/bin/sh
+
+msbindir=/usr/local/libexec/MailScanner
+process=MailScanner
+config=/usr/local/etc/MailScanner/MailScanner.conf
+PIDFILE=/var/run/MailScanner.pid
+
+start_ms()
+{
+    pid=`ps -axww |
+         grep '[ ]'$msbindir/$process |
+         awk '{print $1}'`
+
+    if [ "x$pid" = "x" ]; then
+	# Quietly try to raise the open_files limit
+	ulimit -n 2000 >/dev/null 2>&1
+	# Restart it
+	PATH=${msbindir}:$PATH
+	echo Starting MailScanner...
+	cd $msbindir
+	$process $config
+    else
+	echo MailScanner running with pid $pid  
+    fi
+}
+
+stop_ms()
+{
+    echo Stopping MailScanner...
+    kill -TERM -- -`cat $PIDFILE` 2>/dev/null
+    sleep 5
+}
+
+_action=${1:-start}
+
+case ${_action} in
+start)
+	start_ms
+	;;
+
+stop)
+	stop_ms
+	;;
+
+restart)
+	stop_ms
+	start_ms
+	;;
+
+*)
+	echo "Usage: `basename $0` {start|stop|restart}" >&2
+	exit 64
+	;;
+esac
+exit 0
