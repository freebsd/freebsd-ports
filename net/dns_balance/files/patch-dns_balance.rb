--- dns_balance.rb.orig	Fri Dec 22 12:46:39 2000
+++ dns_balance.rb	Mon Mar  5 16:59:36 2001
@@ -10,6 +10,8 @@
 require 'thread'
 require 'getopts'
 
+$:.unshift "!!PREFIX!!/etc/dns_balance", "!!PREFIX!!/lib/dns_balance"
+
 require 'datatype.rb'
 require 'log_writer.rb'
 require 'util.rb'
@@ -138,9 +140,10 @@
 end
 
 def usage()
-  print "Usage: ruby dns_balance.rb [-lh] [-i ipaddr]\n"
-  print "       -l         print log to stdout\n"
+  print "Usage: dns_balance [-h] [-i ipaddr] [-l logfile] [-p pidfile]\n"
+  print "       -l logfile print log to logfile\n"
   print "       -i ipaddr  listen IP address (default:0.0.0.0)\n"
+  print "       -p pidfile record PID in pidfile\n"
   print "       -h         help message\n"
   exit(111)
 end
@@ -149,9 +152,36 @@
 # main
 
 srand()
-getopts("lh", "i:0.0.0.0")
+getopts("h", "i:0.0.0.0", 'l:', 'p:')
 
 usage() if $OPT_h
+
+exit! if fork
+Process::setsid
+exit! if fork
+STDIN.close
+STDOUT.close
+STDERR.close
+
+$pidfile = nil
+if $OPT_p
+  $pidfile = $OPT_p
+  File::open($pidfile, 'w') { |f| f.puts $$ }
+end
+
+$logout = nil
+if $OPT_l
+  $logout = File::open($OPT_l, 'a+')
+  $logout.sync = true
+end
+
+[0, 2, 3, 5, 10, 13, 15].each do |sig|
+  trap(sig) {
+    File::unlink($pidfile) if $pidfile
+    $logout.close if $logout
+    exit
+  }
+end
 
 put_log("start\n") if $OPT_l
 
