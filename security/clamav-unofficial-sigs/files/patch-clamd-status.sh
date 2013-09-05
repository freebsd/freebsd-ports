--- clamd-status.sh	2013-08-27 18:08:25.000000000 +0200
+++ clamd-status.sh.patched	2013-09-04 16:09:58.000000000 +0200
@@ -24,7 +24,7 @@
 export PATH
 
 # Set path to clamd.pid file (see clamd.conf for path location).
-clamd_pid="/var/run/clamav/clamd.pid"
+clamd_pid="%%CLAMD_PID%%"
 
 # If running clamd in "LocalSocket" mode (*NOT* in TCP/IP mode), and
 # either "SOcket Cat" (socat) or the "IO::Socket::UNIX" perl module
@@ -34,7 +34,7 @@
 # the script will still run).  You will also need to set the correct
 # path to your clamd socket file (if unsure of the path, check the
 # "LocalSocket" setting in your clamd.conf file for socket location).
-clamd_socket="/var/run/clamav/clamd.sock"
+clamd_socket="%%CLAMD_SOCKET%%"
 
 # If you would like to attemtp to restart ClamD if detected not running,
 # uncomment the next 2 lines.  Confirm the path to the "clamd_lock" file
@@ -44,8 +44,8 @@
 # NOTE: these 2 variables are dependant on the "clamd_socket" variable
 # shown above - if not enabled, then the following 2 variables will be
 # ignored, whether enabled or not.
-clamd_lock="/var/lock/subsys/clamd"
-start_clamd="service clamd start"
+clamd_lock=""
+start_clamd="%%START_CLAMD%%"
 
 # To only report issues, set the following variable to "yes".
 only_report_issues="yes"
