--- ./lib/OutputTool.pm.orig	1998-07-23 18:05:21.000000000 -0400
+++ ./lib/OutputTool.pm	2009-07-07 22:30:26.583086913 -0400
@@ -72,7 +72,7 @@
 
 sub makeEndHits {
 	my $self = shift;
-	return "<hr>";
+	return "</UL>";
 }
 
 sub makeLinkOutput {
