--- plugins-scripts/check_mailq.pl.orig	2025-11-08 16:31:19.283295000 +0100
+++ plugins-scripts/check_mailq.pl	2025-11-08 16:39:40.042634000 +0100
@@ -571,7 +571,39 @@ elsif ( $mailq eq "nullmailer" ) {
         $state = $ERRORS{'CRITICAL'};
     }
 } # end of ($mailq eq "nullmailer")
+
+elsif ( $mailq eq "opensmtp" ) {
+       ## open mailq
+       if ( defined $utils::PATH_TO_MAILQ && -x $utils::PATH_TO_MAILQ ) {
+               if (! open (MAILQ, "$sudo $utils::PATH_TO_MAILQ | " ) ) {
+                       print "ERROR: could not open $utils::PATH_TO_MAILQ \n";
+                       exit $ERRORS{'UNKNOWN'};
+               }
+       }elsif( defined $utils::PATH_TO_MAILQ){
+               unless (-x $utils::PATH_TO_MAILQ) {
+                       print "ERROR: $utils::PATH_TO_MAILQ is not executable by (uid $>:gid($)))\n";
+                       exit $ERRORS{'UNKNOWN'};
+               }
+       } else {
+               print "ERROR: \$utils::PATH_TO_MAILQ is not defined\n";
+               exit $ERRORS{'UNKNOWN'};
+       }
+
+       $msg_q++ while (<MAILQ>);
 
+       close(MAILQ) ;
+       if ($msg_q < $opt_w) {
+               $msg = "OK: $mailq mailq ($msg_q) is below threshold ($opt_w/$opt_c)";
+               $state = $ERRORS{'OK'};
+       }elsif ($msg_q >= $opt_w  && $msg_q < $opt_c) {
+               $msg = "WARNING: $mailq mailq is $msg_q (threshold w = $opt_w)";
+               $state = $ERRORS{'WARNING'};
+       }else {
+               $msg = "CRITICAL: $mailq mailq is $msg_q (threshold c = $opt_c)";
+               $state = $ERRORS{'CRITICAL'};
+       }
+} # end of ($mailq eq "opensmtp")
+
 # Perfdata support
 print "$msg|unsent=$msg_q;$opt_w;$opt_c;0\n";
 exit $state;
@@ -635,7 +667,7 @@ sub process_arguments(){
     }
 
     if (defined $opt_M) {
-        if ($opt_M =~ /^(sendmail|qmail|postfix|exim|nullmailer)$/) {
+        if ($opt_M =~ /^(sendmail|qmail|postfix|exim|nullmailer|opensmtp)$/) {
             $mailq = $opt_M ;
         }elsif( $opt_M eq ''){
             $mailq = 'sendmail';
