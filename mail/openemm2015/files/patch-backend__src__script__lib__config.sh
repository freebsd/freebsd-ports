--- backend/src/script/lib/config.sh.orig	2015-02-20 13:02:20 UTC
+++ backend/src/script/lib/config.sh
@@ -34,7 +34,7 @@ host="`uname -n | cut -d. -f1`"
 #
 # Set the base for the whole system ..
 if [ ! "$BASE" ] ; then
-	BASE="$HOME"
+	BASE="/usr/local/openemm2015"
 fi
 export BASE
 optbase="$OPENEMM_SW"
@@ -100,7 +100,7 @@ loglast=0
 #
 # Sendmail location
 #
-sendmail="$HOME/bin/smctrl"
+sendmail="/usr/local/openemm2015/bin/smctrl"
 if [ ! -x $sendmail ]; then
 	sendmail="/usr/sbin/sendmail"
 	if [ ! -x $sendmail ] ; then
@@ -130,7 +130,7 @@ error() {
 	echo "$*" 1>&2
 }
 epoch() {
-		python -c "
+		/usr/local/bin/python2.7 -c "
 import	time
 
 print int (time.time ())
@@ -235,7 +235,7 @@ pathstrip() {
 	if [ $# -ne 1 ] ; then
 		echo "Usage: $0 <path>" 1>&2
 	else
-		python -c "
+		/usr/local/bin/python2.7 -c "
 import	string
 def pathstrip (s):
 	rc = []
@@ -252,7 +252,7 @@ filecount() {
 	if [ $# -ne 2 ] ; then
 		echo "Usage: $0 <dir> <pattern>" 1>&2
 	else
-		python -c "
+		/usr/local/bin/python2.7 -c "
 import	os, sre
 def filecount (directory, pattern):
 	n = 0
@@ -356,7 +356,7 @@ terminator() {
 		shift
 		if [ "$__pat" ] ; then
 			for sig in 15 9 ; do
-				__run="`ps -ef | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
+				__run="`ps -aux | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
 				if [ "$__run" ] ; then
 					messagen "Stop $__pat program with signal $sig .. "
 					kill -$sig $__run >/dev/null 2>&1
@@ -377,12 +377,12 @@ softterm() {
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
@@ -408,7 +408,7 @@ mestopper() {
 			messagen "Creating $__fn, waiting for $__pat: "
 			touch "$__fn"
 			while true ; do
-				__run="`ps -ef | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
+				__run="`ps -aux | grep -- \"$__pat\" | grep -v grep | awk '{ print $2 }'`"
 				if [ ! "$__run" ] ; then
 					break
 				fi
