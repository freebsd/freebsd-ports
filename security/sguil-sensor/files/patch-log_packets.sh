--- sensor/log_packets.sh.orig	Fri Mar 24 13:12:18 2006
+++ sensor/log_packets.sh	Mon Mar 27 17:22:54 2006
@@ -23,37 +23,16 @@
 ##############################################################
 
 
-# Edit these for your setup
+# You shouldn't need to edit anything in this script
 
-# Sensors hostname.
-# Note: If running multiple snort instances, then this must be different
-#       for each instance (ie sensor1, sensor2, sensor-eth0, sensor-eth1, etc)
-HOSTNAME="myhost"
-# Path to snort binary
-SNORT_PATH="/usr/local/bin/snort"
-# Directory to log pcap data to (date dirs will be created in here)
-# Note: The path $HOSTNAME/dailylogs, will be appended to this.
-LOG_DIR="/snort_data"
-# Percentage of disk to try and maintain
-MAX_DISK_USE=90
-# Interface to 'listen' to.
-INTERFACE="eth0"
-# Other options to use when starting snort
-#OPTIONS="-u sguil -g sguil -m 122"
-# Where to store the pid
-PIDFILE="/var/run/snort_log-${HOSTNAME}.pid"
-# How do we run ps
-PS="ps awx"
-# Where is grep
-GREP="/usr/bin/grep"
-#Add BPFs here.
-#The below is an example of a filter for ignoring outbound HTTP from my network
-# to the world.
-#FILTER='not \( src net 67.11.255.148/32 and dst port 80 and "tcp[0:2] > 1024" \) and not \( src port 80 and dst net 67.11.255.148/32 and "tcp[2:2] > 1024"\)'
-
-#Some installs may need these
-#LD_LIBRARY_PATH=/usr/local/lib/mysql
-#export LD_LIBRARY_PATH
+CONF=/usr/local/etc/log_packets.conf
+if [ -r ${CONF} ]; then
+  . ${CONF}
+else
+  echo "Your conf file is either missing or the path "
+  echo "in the log_packets.sh script is incorrect."
+  exit 1
+fi
 
 TZ=GMT
 export TZ
