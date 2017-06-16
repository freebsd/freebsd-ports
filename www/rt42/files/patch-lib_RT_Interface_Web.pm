--- lib/RT/Interface/Web.pm.orig	2016-06-08 21:49:02 UTC
+++ lib/RT/Interface/Web.pm
@@ -1426,7 +1426,7 @@ sub IsCompCSRFWhitelisted {
     # golden.  This acts on the presumption that external forms may
     # hardcode a username and password -- if a malicious attacker knew
     # both already, CSRF is the least of your problems.
-    my $AllowLoginCSRF = not RT->Config->Get('RestrictReferrerLogin');
+    my $AllowLoginCSRF = not RT->Config->Get('RestrictLoginReferrer');
     if ($AllowLoginCSRF and defined($args{user}) and defined($args{pass})) {
         my $user_obj = RT::CurrentUser->new();
         $user_obj->Load($args{user});
@@ -1642,7 +1642,7 @@ sub MaybeShowInterstitialCSRFPage {
     my $token = StoreRequestToken($ARGS);
     $HTML::Mason::Commands::m->comp(
         '/Elements/CSRF',
-        OriginalURL => RT->Config->Get('WebPath') . $HTML::Mason::Commands::r->path_info,
+        OriginalURL => RT->Config->Get('WebBaseURL') . RT->Config->Get('WebPath') . $HTML::Mason::Commands::r->path_info,
         Reason => HTML::Mason::Commands::loc( $msg, @loc ),
         Token => $token,
     );
