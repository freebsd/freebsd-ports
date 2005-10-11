--- lib/AmphetaDesk.pm.orig	Mon Oct 10 17:02:41 2005
+++ lib/AmphetaDesk.pm	Mon Oct 10 17:02:45 2005
@@ -40,7 +40,6 @@
 
 # where are we?
 use FindBin qw($Bin);
-BEGIN { unshift(@INC, catdir($Bin, "lib")); }
 
 ###############################################################################
 # init - creates the environment and sets up the queue based loop.            #
