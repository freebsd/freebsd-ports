--- lib/Video/DVDRip/Subtitle.pm.orig	Wed Dec 29 20:15:32 2004
+++ lib/Video/DVDRip/Subtitle.pm	Wed Dec 29 20:16:34 2004
@@ -193,7 +193,7 @@
 	my %par = @_;
 	my ($filename, $time) = @par{'filename','time'};
 
-	my $catch = qx[identify -ping $filename 2>&1];
+	my $catch = qx[identify $filename 2>&1];
 	my ($width, $height);
 	($width, $height) = ( $catch =~ /(\d+)x(\d+)/ );
 
