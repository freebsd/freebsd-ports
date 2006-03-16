--- lib/XML/RSS.pm.orig	Sun Mar 12 07:47:19 2006
+++ lib/XML/RSS.pm	Thu Mar 16 10:37:37 2006
@@ -1799,6 +1799,7 @@
 	$text =~ s/&(?!(#[0-9]+|#x[0-9a-fA-F]+|\w+);)/&amp;/g;
     $text =~ s/&($entities);/$entity{$1}/g;
     $text =~ s/</&lt;/g;
+    $text =~ s/>/&gt;/g;
 
 	return $text;
 }
