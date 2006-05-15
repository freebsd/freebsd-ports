--- plugins-scripts/check_ircd.pl.orig	Tue May  7 15:05:49 2002
+++ plugins-scripts/check_ircd.pl	Fri May 12 23:40:44 2006
@@ -67,6 +67,7 @@
 $ENV{PATH} = "";
 $ENV{ENV} = "";
 $ENV{BASH_ENV} = "";
+$ENV{CDPATH} = "";
 
 # -----------------------------------------------------------------[ Global ]--
 
