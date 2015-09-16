--- sensor/sancp_agent.tcl.orig	2014-03-29 00:41:36 UTC
+++ sensor/sancp_agent.tcl
@@ -1,6 +1,4 @@
 #!/bin/sh
-# Run tcl from users PATH \
-exec tclsh "$0" "$@"
 
 # $Id: sancp_agent.tcl,v 1.15 2011/03/10 22:03:33 bamm Exp $ #
 
@@ -582,16 +580,16 @@ foreach arg $argv {
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
