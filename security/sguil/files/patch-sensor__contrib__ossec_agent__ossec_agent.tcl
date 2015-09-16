--- sensor/contrib/ossec_agent/ossec_agent.tcl.orig	2014-03-29 00:41:36 UTC
+++ sensor/contrib/ossec_agent/ossec_agent.tcl
@@ -1,6 +1,4 @@
 #!/bin/sh
-# Run tcl from users PATH \
-exec tclsh "$0" "$@"
 
 # OSSEC agent for Sguil 0.7.0.  Based on the "example_agent.tcl" code
 # distributed with sguil.  
@@ -593,9 +591,9 @@ if { ![info exists IPADDR] } {
 if { ![info exists CONF_FILE] } {
 
     # No conf file specified check the defaults
-    if { [file exists /etc/ossec_agent.conf] } {
+    if { [file exists /usr/local/etc/sguil-sensor/ossec_agent.conf] } {
 
-        set CONF_FILE /etc/ossec_agent.conf
+        set CONF_FILE /usr/local/etc/sguil-sensor/ossec_agent.conf
 
     } elseif { [file exists ./ossec_agent.conf] } {
 
@@ -604,7 +602,7 @@ if { ![info exists CONF_FILE] } {
     } else {
 
         puts "Couldn't determine where the ossec_agent.tcl config file is"
-        puts "Looked for /etc/ossec_agent.conf and ./ossec_agent.conf."
+        puts "Looked for /usr/local/etc/sguil-sensor/ossec_agent.conf and ./ossec_agent.conf."
         DisplayUsage $argv0
 
     }
