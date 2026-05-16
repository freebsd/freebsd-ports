--- scripts/ZoneMinder/lib/ZoneMinder/Server.pm.orig	2026-02-16 23:32:05 UTC
+++ scripts/ZoneMinder/lib/ZoneMinder/Server.pm
@@ -127,7 +127,15 @@ sub CpuUsage {
 
   } else {
     # Get CPU utilization percentages
-    my $top_output = `top -b -n 1 | grep -i "^%Cpu(s)" | awk '{print \$2, \$4, \$6, \$8}'`;
+    my $top_output = '';
+    my $uname_output = lc(qx($ZoneMinder::Config{ZM_PATH_UNAME} -s));
+    chomp($uname_output);
+    ## FreeBSD
+    if ($uname_output eq "freebsd") {
+      $top_output = `top -b -d 2 -s 0,2 0 | grep -i "^CPU" | tail -n1 | tr -d '%' | awk '{print \$2, \$6, \$4, \$10}'`;
+    } else {
+      $top_output = `top -b -n 1 | grep -i "^%Cpu(s)" | awk '{print \$2, \$4, \$6, \$8}'`;
+    }
     my ($user, $system, $nice, $idle) = split(/ /, $top_output);
     $user =~ s/[^\d\.]//g;
     $system =~ s/[^\d\.]//g;
