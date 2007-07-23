--- Makefile.PL.orig	Sun Jul 15 16:00:28 2007
+++ Makefile.PL	Sun Jul 15 16:00:31 2007
@@ -17,7 +17,6 @@
     print "running gdome-config... ";
     my $ver = backtick('gdome-config --version');
     my ($major, $minor, $point) = $ver =~ /(\d+).(\d+)\.(\d+)/g;
-    die "VERSION" unless $major == 0 && $minor == 7 && $point == 1;
     $config{LIBS} ||= backtick('gdome-config --libs');
     $config{INC} ||= backtick('gdome-config --cflags');
     print "ok\n";
