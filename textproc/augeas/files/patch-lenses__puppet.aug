--- ./lenses/puppet.aug.orig	2012-05-06 13:14:13.000000000 +0100
+++ ./lenses/puppet.aug	2012-05-06 13:14:45.000000000 +0100
@@ -38,6 +38,7 @@
  *************************************************************************)
 let lns     = IniFile.lns record comment
 
-let filter = (incl "/etc/puppet/puppet.conf")
+let filter = (incl "/etc/puppet/puppet.conf"
+             .incl "%%LOCALBASE%%/etc/puppet/puppet.conf")
 
 let xfm = transform lns filter
