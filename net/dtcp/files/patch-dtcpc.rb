Index: dtcpc.rb
diff -u dtcpc.rb.orig dtcpc.rb
--- dtcpc.rb.orig	2013-06-02 23:05:51.000000000 +0900
+++ dtcpc.rb	2014-05-22 17:24:50.852383194 +0900
@@ -422,6 +422,10 @@
     execute("ifconfig #{@name} mtu #{mtu}")
   end
 
+  def setfib(fibnum)
+    execute("ifconfig #{@name} fib #{fibnum}")
+  end
+
   def linklocal
     `ifconfig #{@name} inet6`.each_line { |s|
       if s =~ /inet6 (fe80::[^ ]*)/
@@ -461,6 +465,9 @@
 	end
       }
     end
+    if $fibnum >= 0
+      setfib($fibnum)
+    end
     @created = true
   end
 
@@ -520,6 +527,9 @@
     if !@tunif || @tunif == "ng"
       @name = mkpeer
       @created = true
+      if $fibnum >= 0
+	setfib($fibnum)
+      end
       return
     end
 
@@ -535,6 +545,9 @@
       @name = mkpeer
       if @name == @tunif
 	@created = true
+	if $fibnum >= 0
+	  setfib($fibnum)
+	end
 	break
       end
 
@@ -927,6 +940,7 @@
 password = ''
 tunif = TUNIF
 cloning = TUNIF_CLONING
+$fibnum = -1
 tuntype = 'tunnelonly'
 route_type = 'static'
 static_routes = 'default'
@@ -949,7 +963,7 @@
 # exit 0
 
 begin
-  params = ARGV.getopts('aA:b:cdDf:i:lm:nop:P:r:R:t:u:U')
+  params = ARGV.getopts('aA:b:cdDfF:i:lm:nop:P:r:R:t:u:U')
 rescue
   usage()
   exit 0
@@ -965,6 +979,7 @@
 $debug = params["d"]
 daemonize = params["D"]
 pidfile = params["f"] if params["f"]
+$fibnum = params["F"].to_i if params["F"]
 tunif = params["i"] if params["i"]
 loop = params["l"]
 mtu = params["m"].to_i if params["m"]
