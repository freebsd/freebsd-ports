--- plugins-scripts/check_ircd.pl.orig	2025-11-08 16:25:06.105511000 +0100
+++ plugins-scripts/check_ircd.pl	2025-11-08 16:27:22.763542000 +0100
@@ -65,6 +65,7 @@ $ENV{'ENV'}='';
 $ENV{'PATH'}='@TRUSTED_PATH@';
 $ENV{'BASH_ENV'}=''; 
 $ENV{'ENV'}='';
+$ENV{CDPATH} = "";
 
 # -----------------------------------------------------------------[ Global ]--
 
