Index: dtcps.rb
diff -u dtcps.rb.orig dtcps.rb
--- dtcps.rb.orig	2013-06-02 23:05:51.000000000 +0900
+++ dtcps.rb	2014-05-19 01:24:45.817292755 +0900
@@ -185,6 +185,10 @@
     execute("ifconfig #{@name} mtu #{mtu}")
   end
 
+  def setfib(fibnum)
+    execute("ifconfig #{@name} fib #{fibnum}")
+  end
+
   def linklocal
     `ifconfig #{@name} inet6`.each_line { |s|
       if s =~ /inet6 (fe80::[^ ]*)/
@@ -226,6 +230,9 @@
 	end
       }
     end
+    if $fibnum >= 0
+      setfib($fibnum)
+    end
     @created = true
   end
 
@@ -291,6 +298,9 @@
     if !@tunif || @tunif == "ng"
       @name = mkpeer
       @created = true
+      if $fibnum >= 0
+	setfib($fibnum)
+      end
       return
     end
 
@@ -306,6 +316,9 @@
       @name = mkpeer
       if @name == @tunif
 	@created = true
+	if $fibnum >= 0
+	  setfib($fibnum)
+	end
 	break
       end
 
@@ -1173,13 +1186,14 @@
 $tunif = TUNIF
 $ng_tunif = "ng"
 $cloning = TUNIF_CLONING
+$fibnum = -1
 $global = nil
 $prefix = nil
 $network_with_peeraddr = nil
 $udp_tunnel_port = UDP_TUNNEL_PORT
 
 begin
-  params = ARGV.getopts('ab:cdDg:i:I:op:U')
+  params = ARGV.getopts('ab:cdDF:g:i:I:op:U')
 rescue
   usage()
   exit 0
@@ -1190,6 +1204,7 @@
 $cloning = false if params["c"]
 $debug = params["d"]
 $daemonize = !params["D"]
+$fibnum = params["F"].to_i if params["F"]
 $global = params["g"] if params["g"]
 $tunif = params["i"] if params["i"]
 $ng_tunif = params["I"] if params["I"]
