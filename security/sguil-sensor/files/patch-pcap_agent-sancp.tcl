--- pcap_agent-sancp.tcl.orig	2012-12-17 22:36:43.000000000 +0000
+++ pcap_agent-sancp.tcl	2012-12-17 22:38:22.000000000 +0000
@@ -1,6 +1,4 @@
 #!/bin/sh
-# Run tcl from users PATH \
-exec tclsh "$0" "$@"
 
 # $Id: pcap_agent-sancp.tcl,v 1.2 2008/05/29 19:25:50 hanashi Exp $ #
 
@@ -754,13 +752,13 @@
 }
 
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
 
@@ -769,7 +767,7 @@
     } else {
 
         puts "Couldn't determine where the pcap_agent.tcl config file is"
-        puts "Looked for /etc/pcap_agent.conf and ./pcap_agent.conf."
+        puts "Looked for /usr/local/etc/sguil-sensor/pcap_agent.conf and ./pcap_agent.conf."
         DisplayUsage $argv0
 
     }
