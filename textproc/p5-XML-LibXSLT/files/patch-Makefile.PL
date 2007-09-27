--- Makefile.PL.orig	Sat Sep  8 18:11:19 2007
+++ Makefile.PL	Thu Sep 27 14:29:35 2007
@@ -30,9 +30,6 @@
         # get libs and inc from gnome-config
         eval {
             print "running xslt-config... ";
-            my $ver = backtick("$xsltcfg --version");
-            my ($major, $minor, $point) = $ver =~ /(\d+)\.(\d+)\.(\d+)/g;
-            die "VERSION" unless $major > 1 || $minor > 0 || $point >= 6;
             $config{LIBS} ||= backtick("$xsltcfg --libs");
             $config{INC} ||= backtick("$xsltcfg --cflags");
             print "ok\n";
