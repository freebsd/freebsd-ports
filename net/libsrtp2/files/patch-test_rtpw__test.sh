--- test/rtpw_test.sh.orig	2024-02-24 08:29:39 UTC
+++ test/rtpw_test.sh
@@ -87,7 +87,7 @@ sleep 1 
 sleep 1 
 
 # verify that the background job is running
-ps -e | grep -q $receiver_pid
+ps x | grep -q $receiver_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -104,7 +104,7 @@ echo $0 ": sender PID = $sender_pid"
 echo $0 ": sender PID = $sender_pid"
 
 # verify that the background job is running
-ps -e | grep -q $sender_pid
+ps x | grep -q $sender_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -136,7 +136,7 @@ sleep 1 
 sleep 1 
 
 # verify that the background job is running
-ps -e | grep -q $receiver_pid
+ps x | grep -q $receiver_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -153,7 +153,7 @@ echo $0 ": sender PID = $sender_pid"
 echo $0 ": sender PID = $sender_pid"
 
 # verify that the background job is running
-ps -e | grep -q $sender_pid
+ps x | grep -q $sender_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
