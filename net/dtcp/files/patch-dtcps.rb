--- dtcps.rb.orig	2013-06-02 14:05:51 UTC
+++ dtcps.rb
@@ -185,6 +185,18 @@ class Interface
     execute("ifconfig #{@name} mtu #{mtu}")
   end
 
+  def setfib(fibnum)
+    execute("ifconfig #{@name} fib #{fibnum}")
+  end
+
+  def setdescr(str = nil)
+    if str == nil
+      execute("ifconfig #{@name} -description >/dev/null 2>&1")
+    else
+      execute("ifconfig #{@name} description #{str} >/dev/null 2>&1")
+    end
+  end
+
   def linklocal
     `ifconfig #{@name} inet6`.each_line { |s|
       if s =~ /inet6 (fe80::[^ ]*)/
@@ -226,6 +238,9 @@ class ClonedInterface < Interface
 	end
       }
     end
+    if $fibnum >= 0
+      setfib($fibnum)
+    end
     @created = true
   end
 
@@ -291,6 +306,9 @@ class NetgraphInterface < Interface
     if !@tunif || @tunif == "ng"
       @name = mkpeer
       @created = true
+      if $fibnum >= 0
+	setfib($fibnum)
+      end
       return
     end
 
@@ -302,10 +320,13 @@ class NetgraphInterface < Interface
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
 
@@ -724,6 +745,7 @@ class Tunnel
       }
       delpeer(@tunif, @info[3], @info[2])
     end
+    tunif.setdescr
     _delete(@tunif)
     @tunif = nil
   end
@@ -769,6 +791,7 @@ class Tunnel
       raise 'tunnel interface sold out'
     end
     debugmsg("#{s}: tunnel interface #{tunif.name}\n")
+    tunif.setdescr(user)
 
     myaddr = nil
     if type == 'host' || (type == 'network' && $network_with_peeraddr)
@@ -883,7 +906,7 @@ end
 def checktraffic(tun)
   return if TRAFFICTIMEOUT == 0
   ipkts = getipkts(tun.name)
-  while TRUE
+  while true
     sleep TRAFFICTIMEOUT
     i = getipkts(tun.name)
     next if i == -1
@@ -899,7 +922,7 @@ end
 
 def service_dtcp(sock, name)
   debugmsg("service_dtcp(#{sock}, #{name})\n")
-  while TRUE
+  while true
     debugmsg("service_dtcp(#{sock}, #{name}) accepting\n")
     Thread.start(sock.accept) { |s|
       debugmsg("service_dtcp(#{sock}, #{name}) accepted #{s}\n")
@@ -912,7 +935,7 @@ def service_dtcp(sock, name)
 
       # check response
       # tunnel itojun RESPONSE type
-      while TRUE
+      while true
 	t = IO.select([s], [], [s], tun == nil ? AUTHTIMEOUT : TUNTIMEOUT)
 	if t == nil
 	  s.print "-ERR connection timed out, disconnecting\r\n"
@@ -1173,13 +1196,14 @@ port = 20200
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
@@ -1190,6 +1214,7 @@ $udp_tunnel_port = params["b"].to_i if params["b"]
 $cloning = false if params["c"]
 $debug = params["d"]
 $daemonize = !params["D"]
+$fibnum = params["F"].to_i if params["F"]
 $global = params["g"] if params["g"]
 $tunif = params["i"] if params["i"]
 $ng_tunif = params["I"] if params["I"]
