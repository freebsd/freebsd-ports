--- sensor/sensor_agent.tcl.orig	Mon Mar 20 20:38:18 2006
+++ sensor/sensor_agent.tcl	Mon Mar 20 20:40:06 2006
@@ -1005,16 +1005,16 @@
   }
 }
 # Parse the config file here
-# Default location is /etc/sensor_agent.conf or pwd
+# Default location is /usr/local/etc/sensor_agent.conf or pwd
 if { ![info exists CONF_FILE] } {
   # No conf file specified check the defaults
-  if { [file exists /etc/sensor_agent.conf] } {
-    set CONF_FILE /etc/sensor_agent.conf
+  if { [file exists /usr/local/etc/sensor_agent.conf] } {
+    set CONF_FILE /usr/local/etc/sensor_agent.conf
   } elseif { [file exists ./sensor_agent.conf] } {
     set CONF_FILE ./sensor_agent.conf
   } else {
     puts "Couldn't determine where the sensor_agent.tcl config file is"
-    puts "Looked for /etc/sensor_agent.conf and ./sensor_agent.conf."
+    puts "Looked for /usr/local/etc/sensor_agent.conf and ./sensor_agent.conf."
     DisplayUsage $argv0
   }
 }
