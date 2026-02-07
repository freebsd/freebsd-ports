--- ./Makefile.pl.orig	2010-01-24 04:35:26.000000000 +0000
+++ ./Makefile.pl	2014-05-21 16:29:01.000000000 +0000
@@ -171,7 +171,7 @@
 	command_build() if(!-e $TARGET);
 	die("Can not install without Config.pm") if($MODULES{Config}==0);
 	$CWD=&cwd if($MODULES{Cwd}>0);
-	my $where=$DESTDIR . $Config{'man3direxp'};
+	my $where=$DESTDIR . $Config{'siteman3direxp'};
 	my $t = $TARGET;
 	if($LIBRARY){
 		$t="$PACKAGE.3pm";
