--- ejabberd.sh.orig	Wed Oct 20 22:16:07 2004
+++ ejabberd.sh	Wed Oct 20 22:14:04 2004
@@ -0,0 +1,90 @@
+#! /bin/sh
+#
+# ejabberd        Start/stop ejabberd server
+#
+#
+
+PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/bin:/usr/local/sbin
+EJABBERD=/usr/local/bin/ejabberd
+EJABBERDCTL=/usr/local/bin/ejabberdctl
+EJABBERDUSER=ejabberd
+NAME=ejabberd
+DESC=ejabberd
+
+test -f $EJABBERD || exit 0
+test -f $EJABBERDCTL || exit 0
+
+# Include ejabberd defaults if available
+if [ -f %%PREFIX%%/etc/ejabberd.defaults ] ; then
+    . %%PREFIX%%/etc/ejabberd.defaults
+fi
+
+
+set -e
+
+status()
+{
+    su $EJABBERDUSER -c "$EJABBERDCTL ejabberd@`hostname -s` status >/dev/null"
+}
+
+start()
+{
+    su $EJABBERDUSER -c "$EJABBERD -noshell -detached"
+}
+
+
+case "$1" in
+    start)
+	    echo -n "Starting $DESC: "
+
+        if status
+        then
+            echo " already running."
+        false
+        else
+            start
+        fi
+
+	    echo "$NAME."
+	;;
+    stop)
+	echo -n "Stopping $DESC: "
+
+       if su $EJABBERDUSER -c "$EJABBERDCTL ejabberd@`hostname -s` stop"
+        then
+            cnt=0
+            while status
+            do
+                cnt=`expr $cnt + 1`
+                if [ $cnt -gt 60 ]
+                then
+                    echo -n " failed "
+                    break
+                fi
+                sleep 1
+                echo -n .
+            done
+        else
+            echo -n " failed "
+        fi
+
+	    echo "$NAME."
+	;;
+    restart|force-reload)
+	    echo -n "Restarting $DESC: "
+        if status
+        then
+            su $EJABBERDUSER -c "$EJABBERDCTL ejabberd@`hostname -s` restart"
+        else
+            start
+        fi
+
+	    echo "$NAME."
+	;;
+    *)
+	echo "Usage: ejabberd.sh {start|stop|restart|force-reload}" >&2
+	exit 1
+	;;
+esac
+
+exit 0
