--- ./Lite/Util/Makefile.PL.orig	2013-07-10 15:38:50.000000000 +0200
+++ ./Lite/Util/Makefile.PL	2013-07-10 15:38:55.000000000 +0200
@@ -205,7 +205,7 @@ sub test_cc {
     return;
   }
 
-  my $CC = $ENV{CC} || $Config{ccname};
+  my $CC = $ENV{CC} || $Config{cc};
   my $command = qq|$CC compile.c -o compile.output|;
 
   print F <<'EOF';
