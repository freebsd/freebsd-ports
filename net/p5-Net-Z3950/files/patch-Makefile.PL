--- Makefile.PL.orig	2007-10-30 15:18:30.000000000 -0700
+++ Makefile.PL	2007-10-30 15:18:48.000000000 -0700
@@ -6,7 +6,7 @@
 #	my $yazconf = "/home/me/stuff/yaz-2.0.4/yaz-config";
 
 my $yazconf = "yaz-config";
-my $yazinc = `$yazconf --cflags`;
+my $yazinc = `$yazconf --cflags | sed 's/ -pthread / /'`;
 my $yazlibs = `$yazconf --libs`;
 if (!$yazinc || !$yazlibs) {
     die "ERROR: Unable to call script 'yaz-config': is YAZ installed?";
