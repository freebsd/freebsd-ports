--- postinstall.pl.orig	2007-07-06 00:42:01.000000000 -0300
+++ postinstall.pl	2013-10-23 21:34:44.000000000 -0200
@@ -1,19 +1,9 @@
 
-if ($^O eq 'MSWin32') {
-	mkdir("/psh");
-	system("xcopy share\\themes \\psh /Y");
-	system("xcopy share\\complete \\psh /Y");
-} else {
 	my $where;
 
-	if( -w '/') {
-		$where= $ARGV[0]||$ARGV[1]||'/usr/local';
-	} else {
-		$where ='~/.psh';
-	}
+	$where= $ARGV[0]||$ARGV[1]||'/usr/local';
 	print "Installing share files to $where/share/psh\n";
 	system("mkdir -p $where/share/psh");
 	system("cp -r share/themes $where/share/psh");
 	system("cp -r share/complete $where/share/psh");
-}
 
