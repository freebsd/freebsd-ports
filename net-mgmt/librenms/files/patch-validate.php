--- validate.php.orig	2017-01-15 20:10:36.344602000 +0000
+++ validate.php	2017-01-15 20:04:36.094612000 +0000
@@ -103,10 +103,10 @@
     print_fail('You need to run this script as root' . (isset($config['user']) ? ' or '.$config['user'] : ''));
 }
 
-if ($config['update_channel'] == 'master' && $cur_sha != $versions['github']['sha']) {
-    $commit_date = new DateTime('@'.$versions['local_date'], new DateTimeZone(date_default_timezone_get()));
-    print_warn("Your install is out of date, last update: " . $commit_date->format('r'));
-}
+#if ($config['update_channel'] == 'master' && $cur_sha != $versions['github']['sha']) {
+#    $commit_date = new DateTime('@'.$versions['local_date'], new DateTimeZone(date_default_timezone_get()));
+#    print_warn("Your install is out of date, last update: " . $commit_date->format('r'));
+#}
 
 // Check php modules we use to make sure they are loaded
 $extensions = array('pcre','curl','session','snmp','mcrypt');
@@ -250,20 +250,20 @@
     print_list($devices, "\t %s\n");
 }
 
-if ($versions['local_branch'] != 'master') {
-    print_warn("Your local git branch is not master, this will prevent automatic updates.");
-}
-
-// check for modified files
-$modifiedcmd = 'git diff --name-only --exit-code';
-if ($username === 'root') {
-    $modifiedcmd = 'su '.$config['user'].' -c "'.$modifiedcmd.'"';
-}
-exec($modifiedcmd, $cmdoutput, $code);
-if ($code !== 0 && !empty($cmdoutput)) {
-    print_warn("Your local git contains modified files, this could prevent automatic updates.\nModified files:");
-    print_list($cmdoutput, "\t %s\n");
-}
+#if ($versions['local_branch'] != 'master') {
+#    print_warn("Your local git branch is not master, this will prevent automatic updates.");
+#}
+#
+#// check for modified files
+#$modifiedcmd = 'git diff --name-only --exit-code';
+#if ($username === 'root') {
+#    $modifiedcmd = 'su '.$config['user'].' -c "'.$modifiedcmd.'"';
+#}
+#exec($modifiedcmd, $cmdoutput, $code);
+#if ($code !== 0 && !empty($cmdoutput)) {
+#    print_warn("Your local git contains modified files, this could prevent automatic updates.\nModified files:");
+#    print_list($cmdoutput, "\t %s\n");
+#}
 
 // Modules test
 $modules = explode(',', $options['m']);
