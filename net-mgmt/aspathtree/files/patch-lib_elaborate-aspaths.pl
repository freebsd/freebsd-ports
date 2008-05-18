
$FreeBSD$

--- lib/elaborate-aspaths.pl.orig
+++ lib/elaborate-aspaths.pl
@@ -364,7 +364,7 @@
 							if ($value1 > 64511 && $value1 < 65535) {
 								push (@asspriv,$value1);
 								push (@{$paths_withasspriv{$value1}}, $key);
-							} elsif ($value1 == 65535 || ($value1 > 32767 && $value1 < 64512)) {
+							} elsif ($value1 == 65535 ) {
 								push (@assreserved,$value1);
 								push (@{$paths_withassreserved{$value1}}, $key);
 							}
@@ -386,7 +386,7 @@
 						if ($value > 64511 && $value < 65535) {
 							push (@asspriv,$value);
 							push (@{$paths_withasspriv{$value}}, $key);
-						} elsif ($value == 65535 || ($value > 32767 && $value < 64512)) {
+						} elsif ($value == 65535 ) {
 							push (@assreserved,$value);
 							push (@{$paths_withassreserved{$value}}, $key);
 						}
