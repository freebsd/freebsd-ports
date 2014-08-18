--- sensor/sancp_agent.tcl.orig	2012-12-17 22:43:39.000000000 +0000
+++ sensor/sancp_agent.tcl	2012-12-17 22:44:56.000000000 +0000
@@ -1,6 +1,4 @@
 #!/bin/sh
-# Run tcl from users PATH \
-exec tclsh "$0" "$@"
 
 # $Id: sancp_agent.tcl,v 1.15 2011/03/10 22:03:33 bamm Exp $ #
 
@@ -582,16 +580,16 @@
   }
 }
 # Parse the config file here
-# Default location is /etc/sancp_agent.conf or pwd
+# Default location is /usr/local/etc/sguil-sensor/sancp_agent.conf or pwd
 if { ![info exists CONF_FILE] } {
   # No conf file specified check the defaults
-  if { [file exists /etc/sancp_agent.conf] } {
-    set CONF_FILE /etc/sancp_agent.conf
+  if { [file exists /usr/local/etc/sguil-sensor/sancp_agent.conf] } {
+    set CONF_FILE /usr/local/etc/sguil-sensor/sancp_agent.conf
   } elseif { [file exists ./sancp_agent.conf] } {
     set CONF_FILE ./sancp_agent.conf
   } else {
     puts "Couldn't determine where the sancp_agent.tcl config file is"
-    puts "Looked for /etc/sancp_agent.conf and ./sancp_agent.conf."
+    puts "Looked for /usr/local/etc/sguil-sensor/sancp_agent.conf and ./sancp_agent.conf."
     DisplayUsage $argv0
   }
 }
