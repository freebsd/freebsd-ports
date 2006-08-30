--- tools/prompt.pl.orig	Wed Aug 30 14:26:45 2006
+++ tools/prompt.pl	Wed Aug 30 14:27:13 2006
@@ -16,7 +16,7 @@
     "\n",
     "Proceed ? [n] ";
 
-my $tmp = <STDIN>;
+my $tmp = $interactive ? <STDIN> : "yes";
 chomp $tmp;
 if ($tmp !~ /^y(?:es)?$/) {
     exit 1;
