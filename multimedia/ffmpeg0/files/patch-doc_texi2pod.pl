--- doc/texi2pod.pl.orig	2015-03-12 00:05:23 UTC
+++ doc/texi2pod.pl
@@ -348,7 +348,7 @@ sub postprocess
     # @* is also impossible in .pod; we discard it and any newline that
     # follows it.  Similarly, our macro @gol must be discarded.
 
-    s/\@anchor{(?:[^\}]*)\}//g;
+    s/\@anchor\{(?:[^\}]*)\}//g;
     s/\(?\@xref\{(?:[^\}]*)\}(?:[^.<]|(?:<[^<>]*>))*\.\)?//g;
     s/\s+\(\@pxref\{(?:[^\}]*)\}\)//g;
     s/;\s+\@pxref\{(?:[^\}]*)\}//g;
