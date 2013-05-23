--- lenses/shellvars.aug.orig	2012-12-17 16:39:45.000000000 -0500
+++ lenses/shellvars.aug	2013-05-13 19:34:17.538347901 -0400
@@ -18,7 +18,7 @@
   let eol = del (/[ \t]+|[ \t]*[;\n]/ . empty_part_re*) "\n"
   let semicol_eol = del (/[ \t]*[;\n]/ . empty_part_re*) "\n"
 
-  let key_re = /[A-Za-z0-9_]+(\[[0-9]+\])?/ - "unset" - "export"
+  let key_re = /[A-Za-z0-9_.]+(\[[0-9]+\])?/ - "unset" - "export"
   let matching_re = "${!" . key_re . /[\*@]\}/
   let eq = Util.del_str "="
 
@@ -201,7 +201,8 @@
   let filter_default = incl "/etc/default/*"
                      . excl "/etc/default/grub_installdevice*"
                      . excl "/etc/default/whoopsie"
-  let filter_misc    = incl "/etc/arno-iptables-firewall/debconf.cfg"
+  let filter_misc    = incl "/boot/loader.conf"
+                     . incl "/etc/arno-iptables-firewall/debconf.cfg"
                      . incl "/etc/cron-apt/config"
                      . incl "/etc/environment"
                      . incl "/etc/blkid.conf"
@@ -213,6 +214,7 @@
                      . incl "/etc/lintianrc"
                      . incl "/etc/lsb-release"
                      . incl "/etc/os-release"
+                     . incl "/etc/periodic.conf"
                      . incl "/etc/popularity-contest.conf"
                      . incl "/etc/rc.conf"
                      . incl "/etc/selinux/config"
