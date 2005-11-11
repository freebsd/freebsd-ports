--- scripts/train.pl.dist	Tue Nov  8 14:34:38 2005
+++ scripts/train.pl	Tue Nov  8 14:36:06 2005
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%PERL%%
 
 # train.pl
 # This tool trains a corpus of messages (a directory containing a nonspam and
@@ -14,7 +14,7 @@
 use vars qw { $USER $PATH $REPORTING_WINDOW $CORPUS $TRAINING_MODE };
 
 $REPORTING_WINDOW  = 250;			# How often to summarize
-$PATH              = "/usr/local/dspam/bin";	# Path to dspam binaries
+$PATH              = "%%DSPAM_PATH%%";		# Path to dspam binaries
 $TRAINING_MODE     = "teft";			# Training mode
 
 ### DO NOT CONFIGURE BELOW THIS LINE ###
