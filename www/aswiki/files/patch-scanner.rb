--- aswiki/scanner.rb.dist	Fri Jan 17 22:56:47 2003
+++ aswiki/scanner.rb	Tue May  4 22:17:21 2004
@@ -97,11 +97,11 @@
 	  q.push [:TABLE_END, tmp]
 	elsif tmp = sc.scan(/\A\|\|/)
 	  q.push [:TABLE, tmp]
-	elsif tmp = sc.scan(/\A\[img:#{URI::REGEXP::PATTERN::X_ABS_URI}\s+[^]]+?\]/xn)
+	elsif tmp = sc.scan(/\A\[img:#{URI::REGEXP::PATTERN::X_ABS_URI}\s+[^\]]+?\]/xn)
 	  q.push [:MOINHREFIMG, tmp]
 	# elsif tmp = sc.scan(/\A\[\S+ +\S+?\]/)
 	# elsif tmp = sc.scan(/\A\[\S+ +[^]]+?\]/)
-	elsif tmp = sc.scan(/\A\[#{URI::REGEXP::PATTERN::X_ABS_URI}\s+[^]]+?\]/xn)
+	elsif tmp = sc.scan(/\A\[#{URI::REGEXP::PATTERN::X_ABS_URI}\s+[^\]]+?\]/xn)
 	  q.push [:MOINHREF, tmp]
 	elsif tmp = sc.scan(/\A\{\{/)
 	  q.push [:ESCAPE_BEGIN, tmp]
