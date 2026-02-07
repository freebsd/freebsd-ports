--- websieve.pl.orig	2023-09-20 11:39:29 UTC
+++ websieve.pl
@@ -640,7 +640,7 @@ sub getuserinfo {
 #creates global variables $mode,@rules,@mailboxes,@quota and %vacation;
 # get quota
 	@quota=&getquota("INBOX") if ($havequota || !$useprocmail);
-	if ($IMAPERROR =~ /no errors/i && !$ismanager && $IMAPERROR) {
+	if ($IMAPERROR !~ /no errors/i && !$ismanager && $IMAPERROR) {
 		$error=$IMAPERROR;
 		&closeimap;
 		&closesieve;
