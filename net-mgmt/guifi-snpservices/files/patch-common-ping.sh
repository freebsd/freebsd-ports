--- ./common/ping.sh.orig	2014-02-21 15:53:13.000000000 +0000
+++ ./common/ping.sh	2014-04-10 14:19:56.000000000 +0000
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
  else
