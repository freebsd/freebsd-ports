--- xs/APR/APR/Makefile.PL.orig	Sun Nov 19 15:31:02 2006
+++ xs/APR/APR/Makefile.PL	Sun Dec  3 15:30:46 2006
@@ -15,7 +15,7 @@
 
 my %args;
 
-%args = map { split /=/, $_ } @ARGV;
+%args = map { split /=/, $_, 2 } @ARGV;
 
 $args{NAME}         = 'APR';
 $args{VERSION_FROM} = 'APR.pm';
