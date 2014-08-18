--- sensor/contrib/ossec_agent/ossec_agent.tcl.orig	2012-12-17 22:47:18.000000000 +0000
+++ sensor/contrib/ossec_agent/ossec_agent.tcl	2012-12-17 22:48:45.000000000 +0000
@@ -1,6 +1,4 @@
 #!/bin/sh
-# Run tcl from users PATH \
-exec tclsh "$0" "$@"
 
 # OSSEC agent for Sguil 0.7.0.  Based on the "example_agent.tcl" code
 # distributed with sguil.  
@@ -593,9 +591,9 @@
 if { ![info exists CONF_FILE] } {
 
     # No conf file specified check the defaults
-    if { [file exists /etc/ossec_agent.conf] } {
+    if { [file exists /usr/local/etc/sguil-sensor/ossec_agent.conf] } {
 
-        set CONF_FILE /etc/ossec_agent.conf
+        set CONF_FILE /usr/local/etc/sguil-sensor/ossec_agent.conf
 
     } elseif { [file exists ./ossec_agent.conf] } {
 
@@ -604,7 +602,7 @@
     } else {
 
         puts "Couldn't determine where the ossec_agent.tcl config file is"
-        puts "Looked for /etc/ossec_agent.conf and ./ossec_agent.conf."
+        puts "Looked for /usr/local/etc/sguil-sensor/ossec_agent.conf and ./ossec_agent.conf."
         DisplayUsage $argv0
 
     }
