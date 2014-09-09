--- lib/net.pm.orig	2014-09-09 15:40:43 UTC
+++ lib/net.pm
@@ -203,7 +203,7 @@
 				while(<IN>) {
 					if(/Link/ && /$nl[$n]/) {
 						# Idrop column added in 8.0
-						if($config->{kernel} gt "7.2") {
+						if($config->{kernel} > "7.2") {
 							(undef, undef, undef, undef, $net_packs_in[$n], $net_error_in[$n], undef, $net_bytes_in[$n], $net_packs_out[$n], $net_error_out[$n], $net_bytes_out[$n]) = split(' ', $_);
 						} else {
 							(undef, undef, undef, undef, $net_packs_in[$n], $net_error_in[$n], $net_bytes_in[$n], $net_packs_out[$n], $net_error_out[$n], $net_bytes_out[$n]) = split(' ', $_);
