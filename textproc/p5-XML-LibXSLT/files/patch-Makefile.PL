--- Makefile.PL.orig	Wed Nov 14 14:11:45 2001
+++ Makefile.PL	Thu Dec  6 15:43:24 2001
@@ -21,9 +21,6 @@
 # get libs and inc from gnome-config
 eval {
     print "running xslt-config... ";
-    my $ver = backtick('xslt-config --version');
-    my ($major, $minor, $point) = $ver =~ /(\d+)\.(\d+)\.(\d+)/g;
-    die "VERSION" unless $major > 1 || $minor > 0 || $point >= 6;
     $config{LIBS} ||= backtick('xslt-config --libs');
     $config{INC} ||= backtick('xslt-config --cflags');
     print "ok\n";
