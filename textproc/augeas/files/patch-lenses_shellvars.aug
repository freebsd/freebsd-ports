--- lenses/shellvars.aug.orig	2015-05-24 00:46:22 UTC
+++ lenses/shellvars.aug
@@ -244,6 +244,7 @@ module Shellvars =
                      . incl "/etc/lintianrc"
                      . incl "/etc/lsb-release"
                      . incl "/etc/os-release"
+                     . incl "/etc/periodic.conf"
                      . incl "/etc/popularity-contest.conf"
                      . incl "/etc/rc.conf"
                      . incl "/etc/rc.conf.local"
