--- lib/Mail/SpamAssassin/Reporter.pm.bak	Wed Jan  9 00:18:48 2002
+++ lib/Mail/SpamAssassin/Reporter.pm	Mon Mar  4 19:52:11 2002
@@ -93,7 +93,6 @@
     require Razor::Client;
     require Razor::Agent;
     local ($^W) = 0;            # argh, warnings in Razor
-    local ($/);                 # argh, bugs in Razor
 
     local $SIG{ALRM} = sub { die "alarm\n" };
     alarm 10;
