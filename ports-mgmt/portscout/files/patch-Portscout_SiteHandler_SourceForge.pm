--- Portscout/SiteHandler/SourceForge.pm.orig	2010-05-05 01:54:16 UTC
+++ Portscout/SiteHandler/SourceForge.pm
@@ -85,7 +85,7 @@ sub CanHandle
 
 	my ($url) = @_;
 
-	return ($url =~ /^http:\/\/[^\/]*?\.sourceforge\.net\/project\//);
+	return ($url =~ /^https?:\/\/[^\/]*?\.sourceforge\.net\/project\//);
 }
 
 
