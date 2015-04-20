--- wqy-unibit/bdfmerge.pl.orig	2007-09-09 22:39:32 UTC
+++ wqy-unibit/bdfmerge.pl
@@ -32,7 +32,7 @@ while(@ARGV>=1&& $ARGV[0]=~/^-{0,1}0[xX]
 {
 	$startpos = hex($1);
 	$endpos=0;
-	$range=shift(ARGV);
+	$range=shift(@ARGV);
 	if($range=~/--0[xX]([0-9A-Fa-f]{0,6})/)
 	{
 		$endpos=hex($1);
