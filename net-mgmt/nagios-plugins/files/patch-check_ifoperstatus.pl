--- plugins-scripts/check_ifoperstatus.pl.orig	Thu May  9 21:03:51 2002
+++ plugins-scripts/check_ifoperstatus.pl	Fri Jul 19 21:29:02 2002
@@ -26,7 +26,7 @@
 # 11.01.2000 Version 1.0
 # $Id: check_ifoperstatus.pl,v 1.1 2002/05/09 19:03:51 sghosh Exp $
 
-use POSIX;
+#use POSIX;
 use strict;
 use lib utils.pm ;
 use utils qw($TIMEOUT %ERRORS &print_revision &support);
