--- lenses/shellvars.aug.orig	2011-11-28 18:51:05.000000000 -0500
+++ lenses/shellvars.aug	2012-05-02 21:42:02.878164637 -0400
@@ -196,6 +196,9 @@
                      . incl "/etc/cron-apt/config"
                      . incl "/etc/environment"
                      . incl "/etc/blkid.conf"
+                     . incl "/etc/rc.conf"
+                     . incl "/etc/periodic.conf"
+                     . incl "/boot/loader.conf"
 
   let filter = filter_sysconfig
              . filter_ifcfg
