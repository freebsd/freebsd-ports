--- lib/Net/Server.pm	Mon Dec  5 22:13:04 2005
+++ lib/Net/Server.pm	Wed Jan 25 08:18:25 2006
@@ -133,6 +133,7 @@
   ### see if we can find the full command line
   if (open _CMDLINE, "/proc/$$/cmdline") { # unix specific
     my $line = do { local $/ = undef; <_CMDLINE> };
+    ($line) = $line =~ /^(.*)$/; # untaint
     close _CMDLINE;
     if ($line) {
       return [split /\0/, $line];
@@ -140,7 +141,8 @@
   }
 
   my $script = $0;
-  $script = $ENV{'PWD'} .'/'. $script if $script =~ m|^\.+/| && $ENV{'PWD'}; # add absolute to relative
+  $script = $ENV{'PWD'} .'/'. $script if $script !~ m|^/| && $ENV{'PWD'}; # add absolute to relative
+  ($script) = $script =~ /^(.*)$/; # untaint
   return [ $script, @ARGV ]
 }
 
