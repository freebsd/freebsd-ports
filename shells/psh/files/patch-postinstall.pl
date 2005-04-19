--- postinstall.pl.orig	Tue Apr 19 10:41:53 2005
+++ postinstall.pl	Tue Apr 19 10:42:00 2005
@@ -1,9 +1,4 @@
 
-if ($^O eq 'MSWin32') {
-	mkdir("/psh");
-	system("xcopy share\\themes \\psh /Y");
-	system("xcopy share\\complete \\psh /Y");
-} else {
 	my $where;
 
 	if( -w '/') {
@@ -15,5 +10,4 @@
 	system("mkdir -p $where/share/psh");
 	system("cp -r share/themes $where/share/psh");
 	system("cp -r share/complete $where/share/psh");
-}
 
