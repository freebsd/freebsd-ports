--- scripts/ZoneMinder/lib/ZoneMinder/Server.pm.orig	2026-10-05 23:07:17 UTC
+++ scripts/ZoneMinder/lib/ZoneMinder/Server.pm
@@ -146,7 +146,7 @@ sub CpuUsage {
     chomp($uname_output);
     my $top_cmd = '';
     if ($uname_output eq 'freebsd') {
-      $top_cmd = q`top -b -n 1 | grep "^CPU" | sed 's/%//g' | awk '{print $2, $6, $4, $10}'`;
+      $top_cmd = q`top -b -d 2 -s 0.2 0 | grep "^CPU" | tail -n1 | tr -d '%' | awk '{print $2, $6, $4, $10}'`;
     } else {
       $top_cmd = q`top -b -n 1 | grep -i "^%Cpu(s)" | awk '{print $2, $4, $6, $8}'`;
     }
