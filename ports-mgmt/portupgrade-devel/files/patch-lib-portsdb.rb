--- lib/portsdb.rb.orig	Mon Jan  2 21:58:23 2006
+++ lib/portsdb.rb	Mon Jan  2 21:58:55 2006
@@ -87,8 +87,11 @@
       while true
 	if moved = @moved[me]
 	  t << moved
-	  me = moved.to
-	  break if me.nil?
+	  if me.nil? or me == moved.to
+	    break
+	  else
+	    me = moved.to
+	  end
 	else
 	  break
 	end
