--- test/rtpw_test_gcm.sh.orig	2024-02-24 08:29:39 UTC
+++ test/rtpw_test_gcm.sh
@@ -84,7 +84,7 @@ sleep 1 
 sleep 1 
 
 # verify that the background job is running
-ps -e | grep -q $receiver_pid
+ps x | grep -q $receiver_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -101,7 +101,7 @@ echo $0 ": sender PID = $sender_pid"
 echo $0 ": sender PID = $sender_pid"
 
 # verify that the background job is running
-ps -e | grep -q $sender_pid
+ps x | grep -q $sender_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -129,7 +129,7 @@ sleep 1 
 sleep 1 
 
 # verify that the background job is running
-ps -e | grep -q $receiver_pid
+ps x | grep -q $receiver_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -146,7 +146,7 @@ echo $0 ": sender PID = $sender_pid"
 echo $0 ": sender PID = $sender_pid"
 
 # verify that the background job is running
-ps -e | grep -q $sender_pid
+ps x | grep -q $sender_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -175,7 +175,7 @@ sleep 1 
 sleep 1 
 
 # verify that the background job is running
-ps -e | grep -q $receiver_pid
+ps x | grep -q $receiver_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -192,7 +192,7 @@ echo $0 ": sender PID = $sender_pid"
 echo $0 ": sender PID = $sender_pid"
 
 # verify that the background job is running
-ps -e | grep -q $sender_pid
+ps x | grep -q $sender_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -220,7 +220,7 @@ sleep 1 
 sleep 1 
 
 # verify that the background job is running
-ps -e | grep -q $receiver_pid
+ps x | grep -q $receiver_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
@@ -237,7 +237,7 @@ echo $0 ": sender PID = $sender_pid"
 echo $0 ": sender PID = $sender_pid"
 
 # verify that the background job is running
-ps -e | grep -q $sender_pid
+ps x | grep -q $sender_pid
 retval=$?
 echo $retval
 if [ $retval != 0 ]; then
