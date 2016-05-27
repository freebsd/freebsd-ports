--- lib/redmine/wiki_formatting/markdown/formatter.rb.orig	2016-05-13 13:44:58 UTC
+++ lib/redmine/wiki_formatting/markdown/formatter.rb
@@ -20,7 +20,7 @@ end  
 
 module Redmine
   module WikiFormatting
-    module Markdown
+    module RedcarpetMarkdown
       class Formatter
         #    include ActionView::Helpers::TagHelper
 
