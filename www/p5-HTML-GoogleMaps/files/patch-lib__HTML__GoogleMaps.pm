--- lib/HTML/GoogleMaps.pm.orig	2006-12-05 20:53:34.000000000 -0800
+++ lib/HTML/GoogleMaps.pm	2008-11-08 01:38:54.000000000 -0800
@@ -41,6 +41,8 @@
 
 =item width => width in pixels
 
+=item ua => UserAgent object used internally
+
 =back
 
 =back
@@ -83,7 +85,7 @@
 =item $map->add_icon(name => $icon_name,
                      image => $image_url,
                      shadow => $shadow_url,
-                     image_size => [ $width, $height ],
+                     icon_size => [ $width, $height ],
                      shadow_size => [ $width, $height ],
                      icon_anchor => [ $x, $y ],
                      info_window_anchor => [ $x, $y ]);
@@ -155,7 +157,7 @@
     %opts,
     points => [],
     poly_lines => [],
-    geocoder => Geo::Coder::Google->new(apikey => $opts{key}),
+    geocoder => Geo::Coder::Google->new(apikey => $opts{key}, ($opts{ua} ? (ua => $opts{ua}) : ())),
   }, $class;
 }
 
@@ -347,7 +349,7 @@
   );
 
   my $text = <<SCRIPT;
-    <script type=\"text/javascript\" />
+    <script type=\"text/javascript\">
     //<![CDATA[
 
     if (GBrowserIsCompatible()) {
