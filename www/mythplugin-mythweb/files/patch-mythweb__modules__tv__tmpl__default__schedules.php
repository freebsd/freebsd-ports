--- mythweb/modules/tv/tmpl/default/schedules.php.orig	2012-05-30 23:22:20.000000000 +0200
+++ mythweb/modules/tv/tmpl/default/schedules.php	2012-07-29 14:17:07.405673220 +0200
@@ -85,6 +85,10 @@
 </tr>
 </thead>
 <?php
+        // Hack:  Disable warnings about "Creating default
+        // object from empty value" from below line
+        // "$schedule->channel->name = '[ '.t('Any').' ]';"
+        ini_set('error_reporting', E_ERROR);
         $prev_group = '';
         $cur_group  = '';
         foreach ($the_schedules as $schedule) {
