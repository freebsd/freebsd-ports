--- Session.pm.orig	Sat Apr  6 16:12:24 2002
+++ Session.pm	Sat Apr  6 16:13:03 2002
@@ -46,7 +46,6 @@
 use strict;
 #use warnings;
 use Carp;
-use Log::Channel;
 use Spread;
 
 use vars qw($VERSION);
@@ -55,9 +54,17 @@
 my $DEFAULT_TIMEOUT = 5;
 
 BEGIN {
-    my $log = new Log::Channel;
+    my ($log, $msglog);
+    if (defined eval "require Log::Channel") {
+	$log = new Log::Channel;
+	$msglog = new Log::Channel("message");
+    } else {
+	# no log::channel, disable all the logging
+	$log = sub {};
+	$msglog = sub {};
+    }
+
     sub sslog { $log->(@_) }
-    my $msglog = new Log::Channel("message");
     sub msglog { $msglog->(@_) }
 }
 
