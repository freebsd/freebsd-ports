--- utils/libcecutil/cec-gen.pl.orig	2020-05-21 11:22:05 UTC
+++ utils/libcecutil/cec-gen.pl
@@ -49,7 +49,7 @@
 	}
 	my @args = split(/, */, $func_args);
 	my $has_struct = $func_args =~ /struct/;
-	return if ($func_args =~ /__u\d+\s*\*/);
+	return if ($func_args =~ /__u\d+\s*\*/ || $func_args =~ /uint\d+_t\s*\*/);
 
 	my $cec_msg = $msg;
 	while ($cec_msg =~ /_/ && !exists($msgs{$cec_msg})) {
