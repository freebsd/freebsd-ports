--- sensor/pcap_agent.tcl.orig	2018-03-31 21:41:21 UTC
+++ sensor/pcap_agent.tcl
@@ -1,6 +1,4 @@
 #!/bin/sh
-# Run tcl from users PATH \
-exec tclsh "$0" "$@"
 
 # $Id: pcap_agent.tcl,v 1.13 2011/03/10 22:03:33 bamm Exp $ #
 
@@ -779,13 +777,13 @@ set BACK_SECONDS 0
 set FWD_SECONDS 0
 
 # Parse the config file here
-# Default location is /etc/pcap_agent.conf or pwd
+# Default location is /usr/local/etc/sguil-sensor/pcap_agent.conf or pwd
 if { ![info exists CONF_FILE] } {
 
     # No conf file specified check the defaults
-    if { [file exists /etc/pcap_agent.conf] } {
+    if { [file exists /usr/local/etc/sguil-sensor/pcap_agent.conf] } {
 
-        set CONF_FILE /etc/pcap_agent.conf
+        set CONF_FILE /usr/local/etc/sguil-sensor/pcap_agent.conf
 
     } elseif { [file exists ./pcap_agent.conf] } {
 
@@ -794,7 +792,7 @@ if { ![info exists CONF_FILE] } {
     } else {
 
         puts "Couldn't determine where the pcap_agent.tcl config file is"
-        puts "Looked for /etc/pcap_agent.conf and ./pcap_agent.conf."
+        puts "Looked for /usr/local/etc/sguil-sensor/pcap_agent.conf and ./pcap_agent.conf."
         DisplayUsage $argv0
 
     }
