Index: lib/portsdb.rb
===================================================================
--- lib/portsdb.rb	(revision 74)
+++ lib/portsdb.rb	(revision 75)
@@ -91,7 +91,7 @@
       while true
 	if moved = @moved[me]
 	  t << moved if t.empty? or t.last.seq < moved.seq
-	  if me.nil? or me == moved.to
+	  if me.nil? or t.map{|p| p.to}.include?(me)
 	    break
 	  else
 	    me = moved.to
