--- core/mui/gtk_postbox.rb.orig	2017-10-08 12:29:16 UTC
+++ core/mui/gtk_postbox.rb
@@ -290,7 +290,7 @@ module Gtk
     def remain_charcount
       if not widget_post.destroyed?
         text = trim_hidden_regions(widget_post.buffer.text + UserConfig[:footer])
-        Twitter::Extractor.extract_urls(text).map{|url|
+        Twitter::TwitterText::Extractor.extract_urls(text).map{|url|
           if url.length < posted_url_length(url)
             -(posted_url_length(url) - url.length)
           else
