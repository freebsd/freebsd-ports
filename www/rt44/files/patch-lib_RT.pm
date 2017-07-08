--- lib/RT.pm.orig	2016-07-18 20:20:17 UTC
+++ lib/RT.pm
@@ -81,6 +81,10 @@ use vars qw($BasePath
  $MasonDataDir
  $MasonSessionDir);
 
+# Set Email::Address module var before anything else loads.
+# This avoids an algorithmic complexity denial of service vulnerability.
+# See T#157608 and CVE-2015-7686 for more information.
+$Email::Address::COMMENT_NEST_LEVEL = 1;
 
 RT->LoadGeneratedData();
 
