--- sensor/snort_agent.tcl.orig	2014-03-29 00:41:36 UTC
+++ sensor/snort_agent.tcl
@@ -1,6 +1,4 @@
 #!/bin/sh
-# Run tcl from users PATH \
-exec tclsh "$0" "$@"
 
 # $Id: snort_agent.tcl,v 1.9 2011/02/17 02:55:48 bamm Exp $ #
 
@@ -680,13 +678,13 @@ foreach arg $argv {
 }
 
 # Parse the config file here
-# Default location is /etc/snort_agent.conf or pwd
+# Default location is /usr/local/etc/sguil-sensor/snort_agent.conf or pwd
 if { ![info exists CONF_FILE] } {
 
     # No conf file specified check the defaults
-    if { [file exists /etc/snort_agent.conf] } {
+    if { [file exists /usr/local/etc/sguil-sensor/snort_agent.conf] } {
 
-        set CONF_FILE /etc/snort_agent.conf
+        set CONF_FILE /usr/local/etc/sguil-sensor/snort_agent.conf
 
     } elseif { [file exists ./snort_agent.conf] } {
 
@@ -695,7 +693,7 @@ if { ![info exists CONF_FILE] } {
     } else {
 
         puts "Couldn't determine where the snort_agent.tcl config file is"
-        puts "Looked for /etc/snort_agent.conf and ./snort_agent.conf."
+        puts "Looked for /usr/local/etc/sguil-sensor/snort_agent.conf and ./snort_agent.conf."
         DisplayUsage $argv0
 
     }
