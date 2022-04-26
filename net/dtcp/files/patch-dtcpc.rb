--- dtcpc.rb.orig	2013-06-02 14:05:51 UTC
+++ dtcpc.rb
@@ -422,6 +422,10 @@ class Interface
     execute("ifconfig #{@name} mtu #{mtu}")
   end
 
+  def setfib(fibnum)
+    execute("ifconfig #{@name} fib #{fibnum}")
+  end
+
   def linklocal
     `ifconfig #{@name} inet6`.each_line { |s|
       if s =~ /inet6 (fe80::[^ ]*)/
@@ -461,6 +465,9 @@ class ClonedInterface < Interface
 	end
       }
     end
+    if $fibnum >= 0
+      setfib($fibnum)
+    end
     @created = true
   end
 
@@ -520,6 +527,9 @@ class NetgraphInterface < Interface
     if !@tunif || @tunif == "ng"
       @name = mkpeer
       @created = true
+      if $fibnum >= 0
+	setfib($fibnum)
+      end
       return
     end
 
@@ -531,10 +541,13 @@ class NetgraphInterface < Interface
     shutdown(@tunif)
 
     bogus = Array.new
-    while TRUE
+    while true
       @name = mkpeer
       if @name == @tunif
 	@created = true
+	if $fibnum >= 0
+	  setfib($fibnum)
+	end
 	break
       end
 
@@ -899,7 +912,7 @@ class DTCPClient
 
   def keep_alive(sock)
     begin
-      while TRUE
+      while true
 	debugmsg("sleep(60)\n")
 	sleep 60
 	sendmsg(sock, "ping")
@@ -927,6 +940,7 @@ ousername = username
 password = ''
 tunif = TUNIF
 cloning = TUNIF_CLONING
+$fibnum = -1
 tuntype = 'tunnelonly'
 route_type = 'static'
 static_routes = 'default'
@@ -949,7 +963,7 @@ pidfile = PIDFILE
 # exit 0
 
 begin
-  params = ARGV.getopts('aA:b:cdDf:i:lm:nop:P:r:R:t:u:U')
+  params = ARGV.getopts('aA:b:cdDfF:i:lm:nop:P:r:R:t:u:U')
 rescue
   usage()
   exit 0
@@ -965,6 +979,7 @@ cloning = false if params["c"]
 $debug = params["d"]
 daemonize = params["D"]
 pidfile = params["f"] if params["f"]
+$fibnum = params["F"].to_i if params["F"]
 tunif = params["i"] if params["i"]
 loop = params["l"]
 mtu = params["m"].to_i if params["m"]
@@ -1013,7 +1028,7 @@ begin
 			      rtadvd_disable)
     dtcpc = DTCPClient.new(dst, port, username, password, tuntype, behind_nat,
 			   mtu, udp_tunnel, udp_tunnel_port)
-    while TRUE
+    while true
       interrupt = nil
       begin
 	trap("SIGHUP") {
