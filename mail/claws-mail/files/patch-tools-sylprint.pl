--- tools/sylprint.pl.orig	Tue Jan  8 20:34:37 2002
+++ tools/sylprint.pl	Tue Jan 15 00:13:15 2002
@@ -36,10 +36,7 @@
 # get user config
 if (defined($ARGV[1]) && $ARGV[1] eq '-r') { $a++; }
 else {
-	@spp = split('/',$0); 
-	$spp[$#spp] = ''; 
-	$spp = join('/',@spp);  
-	$rcf="$spp$rc"; 
+	$rcf="%%PREFIX%%/etc/$rc"; 
 	if (-x $rcf) { do $rcf; }
 	$rcf="$ENV{'HOME'}/.sylpheed/$rc";
 	if (-x $rcf) { do $rcf; }
