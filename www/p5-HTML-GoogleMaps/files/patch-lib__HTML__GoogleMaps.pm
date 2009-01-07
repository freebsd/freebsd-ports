--- lib/HTML/GoogleMaps.pm.orig	2006-12-05 20:53:34.000000000 -0800
+++ lib/HTML/GoogleMaps.pm	2008-11-08 01:38:54.000000000 -0800
@@ -41,6 +41,8 @@
 
 =item width => width in pixels
 
+=item ua => UserAgent object used internally
+
 =back
 
 =back
@@ -155,7 +157,7 @@
     %opts,
     points => [],
     poly_lines => [],
-    geocoder => Geo::Coder::Google->new(apikey => $opts{key}),
+    geocoder => Geo::Coder::Google->new(apikey => $opts{key}, ($opts{ua} ? (ua => $opts{ua}) : ())),
   }, $class;
 }
 
