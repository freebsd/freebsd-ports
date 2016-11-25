--- lib/I18N/LangTags.pm.orig	2004-10-07 07:26:33 UTC
+++ lib/I18N/LangTags.pm
@@ -489,7 +489,7 @@ lookup in %greetings fails.  That's the 
 You could instead do lookups on $wanted with:
 
           use I18N::LangTags qw(same_language_tag);
-          my $repsonse = '';
+          my $response = '';
           foreach my $l2 (keys %greetings) {
             if(same_language_tag($wanted, $l2)) {
               $response = $greetings{$l2};
