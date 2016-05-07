--- ./common/ping.sh.orig	2015-05-22 23:50:50.000000000 +0100
+++ ./common/ping.sh	2016-01-31 18:07:24.559136016 +0000
@@ -1,15 +1,15 @@
 #!/bin/sh
- PING="/bin/ping"
+ PING="/sbin/ping"
  ADDR=$1
- DATA=`$PING -c5 -i 0.2 $ADDR -q -W 4`
+ DATA=`$PING -c 5 -i 0.2 -q -W 4 $ADDR`
  LOSS=`echo $DATA | awk '{print $18 }' | tr -d %`
  ERRORS=`echo $DATA | awk '{print $19 }' | tr -d %`
- if [ $ERRORS = "errors," ]
+ if [ "$ERRORS" = "errors," ]
  then
                LOSS=`echo $DATA | awk '{print $20 }' | tr -d %`
  fi
  echo $LOSS
- if [ $LOSS = 100 ];
+ if [ "$LOSS" = 100 ];
  then
     echo 0
     echo ",$ADDR," >> /tmp/blacklist.snmp
