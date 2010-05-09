--- ./includes/base_signature.inc.php.orig	2010-03-05 16:06:18.000000000 +0100
+++ ./includes/base_signature.inc.php	2010-04-11 23:52:13.000000000 +0200
@@ -139,7 +139,7 @@
       {
          if ($tmp_ref_system_name == "snort")
          {
-           if (ereg("([0-9]+):([0-9]+)", $ref_tag, $backref))
+           if (preg_match("/([0-9]+):([0-9]+)/", $ref_tag, $backref))
            {
              if ($backref[1] == "1")
              {
