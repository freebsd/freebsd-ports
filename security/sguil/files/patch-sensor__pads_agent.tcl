--- sensor/pads_agent.tcl.orig	2014-03-29 00:41:36 UTC
+++ sensor/pads_agent.tcl
@@ -1,6 +1,4 @@
 #!/bin/sh
-# Run tcl from users PATH \
-exec tclsh "$0" "$@"
 
 # $Id: pads_agent.tcl,v 1.13 2011/02/17 02:55:48 bamm Exp $ #
 
@@ -332,7 +330,7 @@ proc Daemonize {} {
   id process group set
   if {[fork]} {exit 0}
   set PID [id process]
-  if { ![info exists PID_FILE] } { set PID_FILE "/var/run/sensor_agent.pid" }
+  if { ![info exists PID_FILE] } { set PID_FILE "/var/run/pads_agent.pid" }
   set PID_DIR [file dirname $PID_FILE]
   if { ![file exists $PID_DIR] || ![file isdirectory $PID_DIR] || ![file writable $PID_DIR] } {
     puts "ERROR: Directory $PID_DIR does not exists or is not writable."
@@ -380,16 +378,16 @@ foreach arg $argv {
   }
 }
 # Parse the config file here
-# Default location is /etc/pads_agent.conf or pwd
+# Default location is /usr/local/etc/sguil-sensor/pads_agent.conf or pwd
 if { ![info exists CONF_FILE] } {
   # No conf file specified check the defaults
-  if { [file exists /etc/pads_agent.conf] } {
-    set CONF_FILE /etc/pads_agent.conf
+  if { [file exists /usr/local/etc/sguil-sensor/pads_agent.conf] } {
+    set CONF_FILE /usr/local/etc/sguil-sensor/pads_agent.conf
   } elseif { [file exists ./pads_agent.conf] } {
     set CONF_FILE ./pads_agent.conf
   } else {
     puts "Couldn't determine where the sensor_agent.tcl config file is"
-    puts "Looked for /etc/pads_agent.conf and ./pads_agent.conf."
+    puts "Looked for /usr/local/etc/sguil-sensor/pads_agent.conf and ./pads_agent.conf."
     DisplayUsage $argv0
   }
 }
