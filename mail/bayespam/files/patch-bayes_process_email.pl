--- bayes_process_email.pl.orig	2016-01-17 18:02:48 UTC
+++ bayes_process_email.pl
@@ -6,6 +6,7 @@ use MIME::Parser;
 use Fcntl;
 use DB_File;
 
+use vars qw($number_of_messages %token_occurrences);
 use Bayespam::Process;
 
 #
@@ -165,8 +166,6 @@ untie( %token_ratings );
 #	dashes, and dollar signs -- words, in other words.
 sub ProcessDirectory
 {
-	our $number_of_messages;
-	our %token_occurrences;
 	my $directory = shift(@_);
 	local *number_of_messages = shift(@_);
 	local *token_occurrences = shift(@_);
@@ -227,7 +226,6 @@ sub ProcessDirectory
 #	dashes, and dollar signs -- words, in other words.
 sub ProcessFile
 {
-	our %token_occurrences;
 	my $file = shift(@_);
 	local *token_occurrences = shift(@_);
 
