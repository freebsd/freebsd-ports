--- ./lib/config.pl.orig	1998-07-27 19:19:55.000000000 -0400
+++ ./lib/config.pl	2009-07-07 22:30:26.560085387 -0400
@@ -36,6 +36,8 @@
 		 addboxes
 		 vhost
 		 usemaxmem
+		 locale
+		 charset
 		 urllist
 );  # in *that* order
 
@@ -101,7 +103,7 @@
 
    # fill in the values so there's *something* there...
    foreach $var (@ConfigVars) {
-      $Values{$var} = "{}";
+      $Values{$var} = "";
    }
 
    foreach $line (@lines) {
