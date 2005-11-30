--- lib/HTML/Mason/Escapes.pm.orig	Tue Aug 23 19:18:12 2005
+++ lib/HTML/Mason/Escapes.pm	Wed Nov 30 12:10:55 2005
@@ -37,6 +37,7 @@
 {
     return unless defined ${ $_[0] };
 
+    use bytes;
     ${ $_[0] } =~ s/([^a-zA-Z0-9_.-])/uc sprintf("%%%02x",ord($1))/eg;
 }
 
