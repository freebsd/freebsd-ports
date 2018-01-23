--- html/includes/rss/rss_parse.inc.orig	2017-12-21 16:55:41.032397000 +0100
+++ html/includes/rss/rss_parse.inc	2017-12-21 16:57:40.079068000 +0100
@@ -150,7 +150,7 @@
         // check for a namespace, and split if found
         $ns = false;
         if ( strpos( $element, ':' ) ) {
-            list($ns, $el) = split( ':', $element, 2); 
+            list($ns, $el) = explode( ':', $element, 2); 
         }
         if ( $ns and $ns != 'rdf' ) {
             $this->current_namespace = $ns;
