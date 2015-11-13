--- src/script/lib/config.sh.orig	2013-09-11 08:30:38 UTC
+++ src/script/lib/config.sh
@@ -34,7 +34,7 @@ host="`uname -n | cut -d. -f1`"
 #
 # Set the base for the whole system ..
 if [ ! "$BASE" ] ; then
-	BASE="$HOME"
+	BASE="/usr/local/openemm2013"
 fi
 export BASE
 optbase="$OPENEMM_SW"
@@ -101,7 +101,7 @@ loglast=0
 #
 # Sendmail location
 #
-sendmail="$HOME/bin/smctrl"
+sendmail="/usr/local/openemm2013/bin/smctrl"
 if [ ! -x $sendmail ]; then
 	sendmail="/usr/sbin/sendmail"
 	if [ ! -x $sendmail ] ; then
@@ -357,7 +357,7 @@ terminator() {
 		shift
 		if [ "$__pat" ] ; then
 			for sig in 15 9 ; do
-				__run="`ps -ef | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
+				__run="`ps -aux | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
 				if [ "$__run" ] ; then
 					messagen "Stop $__pat program with signal $sig .. "
 					kill -$sig $__run >/dev/null 2>&1
@@ -378,12 +378,12 @@ softterm() {
 				repeat="on"
 				while [ $repeat = "on" ]; do
 					repeat="off"
-					__run="`ps -ef | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
+					__run="`ps -aux | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
 					if [ "$__run" ] ; then
 						messagen "Stop $__pat program  .. "
 						kill -15 $__run >/dev/null 2>&1
 						sleep 1
-						__run="`ps -ef | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
+						__run="`ps -aux | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
 						if [ "$__run" ]; then
 							messagen "delaying $sv seconds .. "
 							sleep `expr $sv - 1`
@@ -409,7 +409,7 @@ mestopper() {
 			messagen "Creating $__fn, waiting for $__pat: "
 			touch "$__fn"
 			while true ; do
-				__run="`ps -ef | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
+				__run="`ps -aux | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
 				if [ ! "$__run" ] ; then
 					break
 				fi
