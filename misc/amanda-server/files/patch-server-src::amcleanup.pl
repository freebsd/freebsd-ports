--- server-src/amcleanup.pl.orig	2009-01-28 13:57:21.000000000 +0900
+++ server-src/amcleanup.pl	2009-01-28 13:57:33.000000000 +0900
@@ -94,7 +94,7 @@
 } elsif (!$process_alive) {
     #check amdump/amflush process
     foreach my $pname ("amdump", "amflush") {
-	my $pid = `ps -ef|grep -w ${pname}|grep -w ${config_name}| grep -v grep | awk '{print \$2}'`;
+	my $pid = `ps -f|grep -w ${pname}|grep -w ${config_name}| grep -v grep | awk '{print \$2}'`;
 	chomp $pid;
 	if ($pid ne "") {
 	    $Amanda_process->set_master($pname, $pid);
