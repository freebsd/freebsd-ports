Index: show.cgi
===================================================================
--- show.cgi	(revision 402)
+++ show.cgi	(working copy)
@@ -252,7 +252,7 @@
     @style = ( -style => {-src => "$Config{stylesheet}"} );
   }
   print header, start_html(-id=>"nagiosgraph", -title => "nagiosgraph: $host-$service",
-    -meta => { -http_equiv => "Refresh", -content => "300" },
+    -head => meta({-http_equiv => 'refresh', -content => '300'}),
     @style
     );
   page($host,$service,$geom,$rrdopts,@db);
