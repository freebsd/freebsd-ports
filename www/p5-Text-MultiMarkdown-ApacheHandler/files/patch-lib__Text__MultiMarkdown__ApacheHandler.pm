--- ./lib/Text/MultiMarkdown/ApacheHandler.pm.orig	2013-05-06 13:22:18.000000000 -0400
+++ ./lib/Text/MultiMarkdown/ApacheHandler.pm	2013-05-06 13:25:56.000000000 -0400
@@ -16,6 +16,7 @@
 
 our $VERSION = '0.01';
 
+use Apache2::compat;
 use Apache::Constants qw(:common);
 use Apache::File ();
 use Text::MultiMarkdown 'markdown';
@@ -52,7 +53,7 @@
 	return DECLINED unless $r->content_type() eq 'text/multimarkdown';
 	my $file = $r->filename;
 
-	unless (-e $r->finfo) {
+	unless (-e $file) {
 		$r->log_error("File does not exist: $file");    
 		return NOT_FOUND;
 	}
