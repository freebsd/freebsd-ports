--- lib/FusionInventory/Agent/Task/NetDiscovery.pm	2011-05-05 13:42:10.000000000 +0200
+++ lib/FusionInventory/Agent/Task/NetDiscovery.pm	2012-02-14 16:04:54.652712095 +0100
@@ -41,7 +41,7 @@
 
     $s .= $_ foreach @_;
 
-    return unless $s =~ /Nmap version (\S+) /;
+    return unless $s =~ /Nmap version (\d*\.?\d+)/;
 
     return $1;
 }
