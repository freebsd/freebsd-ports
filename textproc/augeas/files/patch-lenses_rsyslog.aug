--- lenses/rsyslog.aug.orig	2025-07-24 03:58:56.131711000 +0200
+++ lenses/rsyslog.aug	2025-07-24 03:59:27.793860000 +0200
@@ -109,6 +109,8 @@
 
 let filter = incl "/etc/rsyslog.conf"
            . incl "/etc/rsyslog.d/*"
+           . incl "/usr/local/etc/rsyslog.conf"
+           . incl "/usr/local/etc/rsyslog.d/*"
            . Util.stdexcl
 
 let xfm = transform lns filter
