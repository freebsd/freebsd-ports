--- lenses/sysctl.aug.orig	2015-05-24 00:46:35 UTC
+++ lenses/sysctl.aug
@@ -23,7 +23,8 @@ module Sysctl =
 autoload xfm
 
 (* Variable: filter *)
-let filter = incl "/etc/sysctl.conf"
+let filter = incl "boot/loader.conf"
+           . incl "/etc/sysctl.conf"
            . incl "/etc/sysctl.d/*"
            . excl "/etc/sysctl.d/README"
            . excl "/etc/sysctl.d/README.sysctl"
