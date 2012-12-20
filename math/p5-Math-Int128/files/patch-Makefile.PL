--- Makefile.PL	2012-12-10 21:27:04.000000000 +0100
+++ /tmp/Makefile.PL	2012-12-11 07:17:41.000000000 +0100
@@ -14,13 +14,14 @@
                        OBJECT        => '$(O_FILES)',
                       );
 
-my $cc = (grep defined, $mm->{CC}, $Config{cc}, 'cc')[0];
+# my $cc = (grep defined, $mm->{CC}, $Config{cc}, 'cc')[0];
+my $cc = 'gcc44';
 my $cc_version = `$cc --version --verbose 2>&1`;
-unless ($cc_version =~ /^GNU\s+C\s+\([^)]*\)\s+version\s+(4\.(\d+)\S*)/im and $2 >= 4) {
-    unlink $mm->{MAKEFILE};
-    die "This module requires version 4.4 or above of the GCC compiler.\nAborting!\n\n"
-}
-print "GNU C compiler version $1 found, good!\n";
+#unless ($cc_version =~ /^GNU\s+C\s+\([^)]*\)\s+version\s+(4\.(\d+)\S*)/im and $2 >= 4) {
+#    unlink $mm->{MAKEFILE};
+#    die "This module requires version 4.4 or above of the GCC compiler.\nAborting!\n\n"
+#}
+#print "GNU C compiler version $1 found, good!\n";
 
 package MY;
 
