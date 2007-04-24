Index: insert.pl
===================================================================
--- insert.pl	(.../vendor/nagiosgraph/0.8.2/insert.pl)	(revision 1211)
+++ insert.pl	(.../trunk/src/nagiosgraph/insert.pl)	(revision 1211)
@@ -148,9 +148,14 @@
   if ( $ARGV[0] ) {
     @inputlines = $ARGV[0];
   } elsif ( defined $Config{perflog} ) {
-    open PERFLOG, $Config{perflog};
-      @inputlines = <PERFLOG>;
-    close PERFLOG
+    if (-s $Config{perflog}) {
+      my $worklog = $Config{perflog} . ".nagiosgraph";
+      rename($Config{perflog}, $worklog);
+      open PERFLOG, $worklog;
+        @inputlines = <PERFLOG>;
+      close PERFLOG;
+      unlink($worklog);
+    }
   }
 
   # Quit if there are no data to process
