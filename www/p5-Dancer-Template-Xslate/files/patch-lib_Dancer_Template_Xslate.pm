--- lib/Dancer/Template/Xslate.pm.orig	2011-10-24 04:30:40.533601086 +0200
+++ lib/Dancer/Template/Xslate.pm	2011-10-24 04:32:01.720597646 +0200
@@ -14,6 +14,8 @@
 
 my $_engine;
 
+sub default_tmpl_ext { "tx" }
+
 sub init {
     my $self = shift;
 
