--- lib/Creator/FeedCreator.php.orig	2023-04-17 12:24:35 UTC
+++ lib/Creator/FeedCreator.php
@@ -52,6 +52,9 @@ abstract class FeedCreator extends HtmlDescribable
      */
     protected $encoding = "UTF-8"; //"ISO-8859-1";
 
+    protected $_timeout;  # lib/Creator/FeedCreator.php  line 238
+    protected $truncSize; # lib/Creator/PIECreator01.php line 29
+
     /**
      * Any additional elements to include as an associated array. All $key => $value pairs
      * will be included unencoded in the feed in the form
