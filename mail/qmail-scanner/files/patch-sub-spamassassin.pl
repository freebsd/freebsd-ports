--- sub-spamassassin.pl.orig	Mon Sep 29 04:17:22 2003
+++ sub-spamassassin.pl	Thu Dec 11 14:28:48 2003
@@ -57,6 +57,7 @@ sub spamassassin {
     $tag_score .= "SA:1($sa_score/$sa_max):";
     $sa_comment = "Yes, hits=$sa_score required=$sa_max" if ($spamc_options =~ /\-c/);
     &debug("SA: yup, this smells like SPAM");
+    $spam_event = 1;
   }	
   $stop_spamassassin_time=[gettimeofday];
   $spamassassin_time = tv_interval ($start_spamassassin_time, $stop_spamassassin_time);
