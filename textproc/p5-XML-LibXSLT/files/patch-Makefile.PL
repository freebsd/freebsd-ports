--- Makefile.PL.orig	Tue May 22 17:25:19 2001
+++ Makefile.PL	Mon Aug  6 20:43:20 2001
@@ -19,9 +19,6 @@
 # get libs and inc from gnome-config
 eval {
     print "running xslt-config... ";
-    my $ver = backtick('xslt-config --version');
-    my ($major, $minor) = $ver =~ /(\d+)\.(\d+)/g;
-    die "VERSION" unless $minor >= 7;
     $config{LIBS} ||= backtick('xslt-config --libs');
     $config{INC} ||= backtick('xslt-config --cflags');
     print "ok\n";
@@ -102,8 +99,9 @@
     }
     open(OLDOUT, ">&STDOUT");
     open(OLDERR, ">&STDERR");
-    open(STDOUT, ">" . File::Spec->devnull);
-    open(STDERR, ">" . File::Spec->devnull);
+    my $devnull = eval { File::Spec->devnull} || "/dev/null";
+    open(STDOUT, ">$devnull");
+    open(STDERR, ">$devnull");
     my $retval = system($command);
     open(STDOUT, ">&OLDOUT");
     open(STDERR, ">&OLDERR");
@@ -126,8 +124,9 @@
     }
     open(OLDOUT, ">&STDOUT");
     open(OLDERR, ">&STDERR");
-    open(STDOUT, ">" . File::Spec->devnull);
-    open(STDERR, ">" . File::Spec->devnull);
+    my $devnull = eval { File::Spec->devnull} || "/dev/null";
+    open(STDOUT, ">$devnull");
+    open(STDERR, ">$devnull");
     my $results = `$command`;
     my $retval = $?;
     open(STDOUT, ">&OLDOUT");
