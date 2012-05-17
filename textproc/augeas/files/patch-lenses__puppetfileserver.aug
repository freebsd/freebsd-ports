--- ./lenses/puppetfileserver.aug.orig	2012-05-06 13:14:17.000000000 +0100
+++ ./lenses/puppetfileserver.aug	2012-05-06 13:15:08.000000000 +0100
@@ -105,6 +105,7 @@
 let lns = IniFile.lns record comment
 
 (* Variable: filter *)
-let filter = (incl "/etc/puppet/fileserver.conf")
+let filter = (incl "/etc/puppet/fileserver.conf"
+             .incl "%%LOCALBASE%%/etc/puppet/fileserver.conf")
 
 let xfm = transform lns filter
