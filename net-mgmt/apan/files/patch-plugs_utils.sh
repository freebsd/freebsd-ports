
$FreeBSD$

--- plugs/utils.sh.orig	Fri Mar 26 13:44:47 2004
+++ plugs/utils.sh	Mon Mar 29 16:58:13 2004
@@ -20,7 +20,39 @@
 			ERR=1
 		fi
 		#debug "Ping: $HOST, RTT: $RTT"
-		RTT=`echo $RTT/1000|bc -l`
+		#RTT=`echo $RTT/1000|bc -l`
+		dsname=${NAMELIST[$N]}
+		RETVAL=$STATUS
+		TEMPL=`echo "${TEMPL}:$dsname"`
+		DATA=`echo "${DATA}:$RTT"`
+		N=`expr $N + 1`
+	done
+		RETSTR="$RES"
+}
+
+	
+fping() {
+	RETSTR=""
+	#debug "FPING1: $HOST, '$ARGS'"
+	for if in `echo $ARGS|tr "|" " "`; do
+		RES=`$PLUGINSDIR/check_fping $HOST -w $WARN -c $CRIT -n 5`
+		STATUS=$?
+		#debug "FPING2: $HOST, $STATUS, '$RES'"
+		if [ $STATUS -gt 2 ]; then
+			RETVAL=3
+			RETSTR=$RES
+			ERR=1
+			break
+		fi
+		RTT=`echo $RES|cut -d "," -f 2|cut -d "=" -f 2|tr -d " [a-zA-Z)]"`
+		#debug "FPing3: $HOST, RTT: $RTT"
+
+		MINUS=`echo $RTT|grep "-"`
+		if [ "$MINUS" != "" ]; then
+			ERR=1
+		fi
+		#debug "FPing4: $HOST, RTT: $RTT"
+		#RTT=`echo $RTT*1000|bc -l`
 		dsname=${NAMELIST[$N]}
 		RETVAL=$STATUS
 		TEMPL=`echo "${TEMPL}:$dsname"`
