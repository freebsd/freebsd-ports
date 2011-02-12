--- pivotx/data.php.orig	2010-11-02 05:17:24.000000000 +0900
+++ pivotx/data.php	2011-01-05 16:04:08.000000000 +0900
@@ -609,9 +609,11 @@
         'allow_comments' => '1',
         'allow_paragraphs' => '0',
         'chmod' => '0644',
+        'chmod_dir' => '0755',
         'cookie_length' => '1814400',
         'db_version' => $dbversion,
         'debug' => 0,
+        //'debug_visible' => 1,
         'default_category' => 'default',
         'diffdate_format' => '%ordday% %monname% \'%ye% - ',
         'emoticons' => '1',
