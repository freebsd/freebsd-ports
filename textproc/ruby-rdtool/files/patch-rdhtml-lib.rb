--- rd/rd2html-lib.rb.orig	Wed Jun  6 02:20:47 2001
+++ rd/rd2html-lib.rb	Sat Dec  8 21:49:40 2001
@@ -347,7 +347,7 @@
     def apply_to_Foottext(element, content)
       num = get_footnote_num(element)
       raise ArgumentError, "[BUG] #{element} isn't registered." unless num
-      %|<a name="foottext:#{num}" id="foottext:#{num}" href="footmark:#{num}">|+
+      %|<a name="foottext:#{num}" id="foottext:#{num}" href="#footmark:#{num}">|+
 	%|<sup><small>*#{num}</small></sup></a>| +
 	%|<small>#{content}</small><br />|
     end
