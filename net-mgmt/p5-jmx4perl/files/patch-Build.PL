--- Build.PL.orig	2012-12-06 01:52:11.000000000 +0000
+++ Build.PL	2012-12-06 01:55:18.000000000 +0000
@@ -73,7 +73,7 @@
 EOT
 
 chomp $msg;
-my $answer = y_n($msg,"y");
+my $answer = 1;
 if ($answer) {
     add_reqs(
               "Nagios::Plugin" => "0.27", # req
@@ -97,7 +97,7 @@
 Install 'cacti_jmx4perl' ? (y/n)
 EOT
 chomp $msg;
-$answer = y_n($msg,"y");
+$answer = 1;
 if ($answer) {
     add_reqs(
               "Nagios::Plugin" => "0.27", # req
@@ -121,7 +121,7 @@
 Install 'j4psh' ? (y/n)
 EOT
 chomp $msg;
-$answer = y_n($msg,"y");
+$answer = 1;
 
 if ($answer) {
     add_reqs(
@@ -169,7 +169,7 @@
 Install 'jolokia' ? (y/n)
 EOT
 chomp $msg;
-$answer = y_n($msg,"y");
+$answer = 1;
 if ($answer) {
     add_reqs(
               "Archive::Zip" => 0,        # req
