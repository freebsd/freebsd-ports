--- NNTPGateway.pm.orig	Mon Dec  8 20:42:03 2003
+++ NNTPGateway.pm	Mon Dec  8 20:42:19 2003
@@ -118,8 +118,8 @@
 
 # MESSAGES, stuff that is printed on the user's screen... The current default
 # language: Should be an entry in Messages_Map & LANGS_OK
-my $USR_LANG = 'fr';
-#my $USR_LANG = 'en';
+#my $USR_LANG = 'fr';
+my $USR_LANG = 'en';
 # Allowed languages choice.
 my %LANGS_OK = ( 'fr' => 1, 'en' => 1 );
 
