Index: dtcps.rb
diff -u dtcps.rb.orig dtcps.rb
--- dtcps.rb.orig	2013-06-02 23:05:51.000000000 +0900
+++ dtcps.rb	2014-05-22 17:24:50.868385076 +0900
@@ -185,6 +185,18 @@
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
@@ -226,6 +238,9 @@
 	end
       }
     end
+    if $fibnum >= 0
+      setfib($fibnum)
+    end
     @created = true
   end
 
@@ -291,6 +306,9 @@
     if !@tunif || @tunif == "ng"
       @name = mkpeer
       @created = true
+      if $fibnum >= 0
+	setfib($fibnum)
+      end
       return
     end
 
@@ -306,6 +324,9 @@
       @name = mkpeer
       if @name == @tunif
 	@created = true
+	if $fibnum >= 0
+	  setfib($fibnum)
+	end
 	break
       end
 
@@ -724,6 +745,7 @@
       }
       delpeer(@tunif, @info[3], @info[2])
     end
+    tunif.setdescr
     _delete(@tunif)
     @tunif = nil
   end
@@ -769,6 +791,7 @@
       raise 'tunnel interface sold out'
     end
     debugmsg("#{s}: tunnel interface #{tunif.name}\n")
+    tunif.setdescr(user)
 
     myaddr = nil
     if type == 'host' || (type == 'network' && $network_with_peeraddr)
@@ -1173,13 +1196,14 @@
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
@@ -1190,6 +1214,7 @@
 $cloning = false if params["c"]
 $debug = params["d"]
 $daemonize = !params["D"]
+$fibnum = params["F"].to_i if params["F"]
 $global = params["g"] if params["g"]
 $tunif = params["i"] if params["i"]
 $ng_tunif = params["I"] if params["I"]
