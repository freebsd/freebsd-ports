--- sub-spamassassin.pl.orig	Thu Dec  4 22:17:55 2003
+++ sub-spamassassin.pl	Mon Mar 15 01:27:28 2004
@@ -61,6 +61,7 @@
     $tag_score .= "SA:1($sa_score/$sa_max):";
     $sa_comment = "Yes, hits=$sa_score required=$sa_max" if ($sa_fast);
     &debug("SA: yup, this smells like SPAM");
+    $spam_event = 1;
   }	
   if ($sa_score > 0) {
     $sa_score=int($sa_score);
