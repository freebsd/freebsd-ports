--- utils/cec-ctl/msg2ctl.pl.orig	2020-04-09 16:29:54 UTC
+++ utils/cec-ctl/msg2ctl.pl
@@ -49,7 +49,7 @@ sub process_func
 	}
 	my @args = split(/, */, $func_args);
 	my $has_struct = $func_args =~ /struct/;
-	return if ($func_args =~ /__u\d+\s*\*/);
+	return if ($func_args =~ /__u\d+\s*\*/ || $func_args =~ /uint\d+_t\s*\*/);
 
 	my $cec_msg = $msg;
 	while ($cec_msg ne "" && !exists($msgs{$cec_msg})) {
