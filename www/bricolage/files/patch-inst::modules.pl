--- inst/modules.pl.orig	Fri Dec 12 16:14:45 2003
+++ inst/modules.pl	Sat May 22 15:11:30 2004
@@ -36,6 +36,10 @@
 use File::Spec::Functions;
 use Data::Dumper;
 
+# check whether questions should be asked
+our $QUIET;
+$QUIET = 1 if $ARGV[0] and $ARGV[0] eq 'QUIET';
+
 print "\n\n==> Probing Required Perl Modules <==\n\n";
 
 our @MOD;
@@ -48,9 +52,9 @@
 foreach my $rec (@MOD) {
     $rec->{found} = check_module($rec);
     unless ($rec->{found}) {
-        if ($rec->{optional} and 
-            not ask_yesno("Do you want to install the optional module " . 
-                          "$rec->{name}? [no] ", 0)) {
+        if ($rec->{optional} and ($QUIET
+                or not ask_yesno("Do you want to install the optional module " . 
+                          "$rec->{name}? [no] ", 0))) {
             $rec->{found} = 1;
         } else {
             $MISSING = 1;
@@ -73,7 +77,9 @@
 END
 
     # for some reason an "exit 1" here doesn't stop the make run.
-    kill(2, $$) unless ask_yesno("Continue? [yes] ", 1);
+    if ($QUIET or not ask_yesno("Continue? [yes] ", 1)) {
+        kill(2, $$);
+    }
 }
 
 
