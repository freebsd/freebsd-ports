--- validate.php.orig	2017-04-11 18:45:34 UTC
+++ validate.php
@@ -108,13 +108,6 @@ if (!($username === 'root' || (isset($co
     print_fail('You need to run this script as root' . (isset($config['user']) ? ' or '.$config['user'] : ''));
 }
 
-if ($git_found === true) {
-    if ($config['update_channel'] == 'master' && $cur_sha != $versions['github']['sha']) {
-        $commit_date = new DateTime('@'.$versions['local_date'], new DateTimeZone(date_default_timezone_get()));
-        print_warn("Your install is out of date, last update: " . $commit_date->format('r'));
-    }
-}
-
 // Check php modules we use to make sure they are loaded
 $extensions = array('pcre','curl','session','snmp','mcrypt');
 foreach ($extensions as $extension) {
@@ -302,22 +295,6 @@ if (dbFetchCell('SELECT COUNT(*) FROM `d
 }
 
 
-if ($git_found === true) {
-    if ($versions['local_branch'] != 'master') {
-        print_warn("Your local git branch is not master, this will prevent automatic updates.");
-    }
-
-    // check for modified files
-    $modifiedcmd = 'git diff --name-only --exit-code';
-    if ($username === 'root') {
-        $modifiedcmd = 'su '.$config['user'].' -c "'.$modifiedcmd.'"';
-    }
-    exec($modifiedcmd, $cmdoutput, $code);
-    if ($code !== 0 && !empty($cmdoutput)) {
-        print_warn("Your local git contains modified files, this could prevent automatic updates.\nModified files:");
-        print_list($cmdoutput, "\t %s\n");
-    }
-}
 // Modules test
 $modules = explode(',', $options['m']);
 foreach ($modules as $module) {
