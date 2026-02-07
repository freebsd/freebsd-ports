--- tools/prompt.pl.orig	Sat Mar 17 01:47:32 2007
+++ tools/prompt.pl	Tue May  1 20:41:18 2007
@@ -17,7 +17,7 @@
     "\n",
     "Proceed ? [n] ";
 
-$tmp = <STDIN>;
+$tmp = $interactive ? <STDIN> : "yes";
 chomp $tmp;
 if ($tmp !~ /^y(?:es)?$/) {
     exit 1;
