--- lib/RSS.pm.orig	Wed Apr 21 15:14:43 2004
+++ lib/RSS.pm	Wed Apr  6 13:06:54 2005
@@ -1800,6 +1800,7 @@
 	$text =~ s/&(?!(#[0-9]+|#x[0-9a-fA-F]+|\w+);)/&amp;/g;
     $text =~ s/&($entities);/$entity{$1}/g;
     $text =~ s/</&lt;/g;
+    $text =~ s/>/&gt;/g;
 
 	return $text;
 }
