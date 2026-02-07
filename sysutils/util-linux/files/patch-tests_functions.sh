--- tests/functions.sh.orig	2025-06-23 11:25:00 UTC
+++ tests/functions.sh
@@ -479,8 +479,8 @@ function ts_init_suid {
 
 	# Save info about original setting
 	TS_SUID_PROGS[$ct]=$PROG
-	TS_SUID_USER[$ct]=$(stat --printf="%U" $PROG)
-	TS_SUID_GROUP[$ct]=$(stat --printf="%G" $PROG)
+	TS_SUID_USER[$ct]=$(stat -f "%Su" $PROG)
+	TS_SUID_GROUP[$ct]=$(stat -f "%Sg" $PROG)
 
 	chown root:root $PROG &> /dev/null
 	chmod u+s $PROG &> /dev/null
@@ -688,12 +688,13 @@ function ts_cleanup_on_exit {
 }
 
 function ts_cleanup_on_exit {
-
-	for idx in $(seq 0 $((${#TS_SUID_PROGS[*]} - 1))); do
-		PROG=${TS_SUID_PROGS[$idx]}
-		chmod a-s $PROG &> /dev/null
-		chown ${TS_SUID_USER[$idx]}:${TS_SUID_GROUP[$idx]} $PROG &> /dev/null
-	done
+	if [ ${#TS_SUID_PROGS[*]} -ge 1 ] ; then
+		for idx in $(seq 0 $((${#TS_SUID_PROGS[*]} - 1))); do
+			PROG=${TS_SUID_PROGS[$idx]}
+			chmod a-s $PROG &> /dev/null
+			chown ${TS_SUID_USER[$idx]}:${TS_SUID_GROUP[$idx]} $PROG &> /dev/null
+		done
+	fi
 
 	for dev in "${TS_LOOP_DEVS[@]}"; do
 		ts_device_deinit "$dev"
