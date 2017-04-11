--- etc/95.pl.orig	2016-11-04 16:36:01 UTC
+++ etc/95.pl
@@ -31,7 +31,7 @@ $pass="rtgdefault";
 $onedaysec=60*60*24;
 
 # Default locations to find RTG configuration file
-@configs = ("rtg.conf", "/usr/local/rtg/etc/rtg.conf", "/etc/rtg.conf");
+@configs = ("rtg.conf", "%%PREFIX%%/etc/rtg/rtg.conf", "/usr/local/rtg/etc/rtg.conf", "/etc/rtg.conf");
 foreach $conf (@configs) {
   if (open CONF, "<$conf") {
     print "Reading [$conf].\n" if $DEBUG;
