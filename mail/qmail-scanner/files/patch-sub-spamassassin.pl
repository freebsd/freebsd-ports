--- sub-spamassassin.pl.orig	Mon Sep 29 04:17:22 2003
+++ sub-spamassassin.pl	Sun Jan  4 16:17:55 2004
@@ -57,6 +57,7 @@
     $tag_score .= "SA:1($sa_score/$sa_max):";
     $sa_comment = "Yes, hits=$sa_score required=$sa_max" if ($spamc_options =~ /\-c/);
     &debug("SA: yup, this smells like SPAM");
+    $spam_event = 1;
   }	
   $stop_spamassassin_time=[gettimeofday];
   $spamassassin_time = tv_interval ($start_spamassassin_time, $stop_spamassassin_time);
