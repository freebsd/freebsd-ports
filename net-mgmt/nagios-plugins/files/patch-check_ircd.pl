--- plugins-scripts/check_ircd.pl.orig	Tue May  7 07:35:49 2002
+++ plugins-scripts/check_ircd.pl	Wed Aug 11 21:15:56 2004
@@ -67,6 +67,7 @@
 $ENV{PATH} = "";
 $ENV{ENV} = "";
 $ENV{BASH_ENV} = "";
+$ENV{CDPATH} = "";
 
 # -----------------------------------------------------------------[ Global ]--
 
