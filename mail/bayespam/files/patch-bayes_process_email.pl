--- bayes_process_email.pl.orig	Sun Sep  8 16:48:05 2002
+++ bayes_process_email.pl	Sun Sep  8 16:48:28 2002
@@ -6,6 +6,7 @@
 use Fcntl;
 use DB_File;
 
+use vars qw($number_of_messages %token_occurrences);
 use Bayespam::Process;
 
 #
@@ -165,8 +166,6 @@
 #	dashes, and dollar signs -- words, in other words.
 sub ProcessDirectory
 {
-	our $number_of_messages;
-	our %token_occurrences;
 	my $directory = shift(@_);
 	local *number_of_messages = shift(@_);
 	local *token_occurrences = shift(@_);
@@ -227,7 +226,6 @@
 #	dashes, and dollar signs -- words, in other words.
 sub ProcessFile
 {
-	our %token_occurrences;
 	my $file = shift(@_);
 	local *token_occurrences = shift(@_);
 
