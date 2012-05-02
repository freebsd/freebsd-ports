--- ./lenses/shellvars.aug.orig	2012-05-01 13:51:21.934163842 -0400
+++ ./lenses/shellvars.aug	2012-05-01 13:52:04.015160071 -0400
@@ -196,6 +196,7 @@
                      . incl "/etc/cron-apt/config"
                      . incl "/etc/environment"
                      . incl "/etc/blkid.conf"
+                     . incl "/etc/rc.conf"
 
   let filter = filter_sysconfig
              . filter_ifcfg
