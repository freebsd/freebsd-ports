--- scripts/ZoneMinder/lib/ZoneMinder/Server.pm.orig	2026-05-28 12:42:49 UTC
+++ scripts/ZoneMinder/lib/ZoneMinder/Server.pm
@@ -132,7 +132,7 @@ sub CpuUsage {
     chomp($uname_output);
     ## FreeBSD
     if ($uname_output eq "freebsd") {
-      $top_output = `top -b -n 1 | grep "^CPU" | sed 's/%//g' | awk '{print \$2, \$6, \$4, \$10}'`;
+      $top_output = `top -b -d 2 -s 0.2 0 | grep -i "^CPU" | tail -n1 | tr -d '%' | awk '{print \$2, \$6, \$4, \$10}'`;
     } else {
       $top_output = `top -b -n 1 | grep -i "^%Cpu(s)" | awk '{print \$2, \$4, \$6, \$8}'`;
     }
