--- Makefile.PL.orig	Tue Jul 11 13:51:40 2006
+++ Makefile.PL	Tue Jul 11 13:51:47 2006
@@ -13,7 +13,7 @@
     LWP::Simple             0
     Image::Size             0
     PDF::Writer             0.05
-    PDF::Template           0.30
+    PDF::Template           0.22
 );
 
 unless (can_use('PDF::API2') or can_use('pdflib_pl')) {
