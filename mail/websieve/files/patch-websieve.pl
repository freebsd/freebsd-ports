--- websieve.pl.orig	Tue Jul  6 21:20:09 2004
+++ websieve.pl	Sat Sep 29 16:02:22 2007
@@ -640,7 +640,7 @@
 #creates global variables $mode,@rules,@mailboxes,@quota and %vacation;
 # get quota
 	@quota=&getquota("INBOX") if ($havequota || !$useprocmail);
-	if ($IMAPERROR =~ /no errors/i && !$ismanager && $IMAPERROR) {
+	if ($IMAPERROR !~ /no errors/i && !$ismanager && $IMAPERROR) {
 		$error=$IMAPERROR;
 		&closeimap;
 		&closesieve;
