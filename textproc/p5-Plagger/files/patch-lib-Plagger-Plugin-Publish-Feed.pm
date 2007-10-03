--- lib/Plagger/Plugin/Publish/Feed.pm-
+++ lib/Plagger/Plugin/Publish/Feed.pm
@@ -148,14 +154,15 @@
 
 *XML::Feed::Entry::RSS::add_enclosure = sub {
     my($entry, $enclosure) = @_;
-    $entry->{entry}->{enclosure} = {
-        url    => $enclosure->{url},
-        type   => $enclosure->{type},
-        length => $enclosure->{length},
-    };
+    $entry->{entry}->{enclosure} = XML::RSS::LibXML::MagicElement->new(
+        attributes => {
+            url    => $enclosure->{url},
+            type   => $enclosure->{type},
+            length => $enclosure->{length},
+        }
+    );
 };
 
-
 1;
 
 __END__
