--- bin/SetPermissions.sh	Tue Jul  4 13:47:02 2006
+++ bin/SetPermissions.sh	Tue Jul  4 13:49:39 2006
@@ -108,10 +108,11 @@
 chown -R $WEBUSER:$WEBGROUP $OTRSDEST/var/sessions/
 
 # set the var/log/TicketCounter.log file to OTRS and webserver user
-echo "touch && chown $OTRSUSER:$WEBGROUP $OTRSDEST/var/log/TicketCounter.log"
-touch $OTRSDEST/var/log/TicketCounter.log
-chown $OTRSUSER:$WEBGROUP $OTRSDEST/var/log/TicketCounter.log
-chmod 664 $OTRSDEST/var/log/TicketCounter.log
+if test -e $OTRSDEST/var/log/TicketCounter.log; then
+    echo "chown $OTRSUSER:$WEBGROUP $OTRSDEST/var/log/TicketCounter.log"
+    chown $OTRSUSER:$WEBGROUP $OTRSDEST/var/log/TicketCounter.log
+    chmod 664 $OTRSDEST/var/log/TicketCounter.log
+fi
 
 # --
 # bin/*
