--- tools/bb_start.pl.org	Thu Feb  9 11:28:48 2006
+++ tools/bb_start.pl	Thu Feb  9 11:29:11 2006
@@ -178,7 +178,7 @@
 
 sub proclist {
     my @result;
-    foreach my $cmd ( "ps cax", "ps -e", "ps -ef" ) {
+    foreach my $cmd ( "ps ax" ) {
 	open( CMD, "$cmd 2>/dev/null|" );
 	@result = ();
 	while( <CMD> ) {
