--- ./class/deliver/Deliver.class.php.orig	2009-04-15 18:00:49.000000000 -0400
+++ ./class/deliver/Deliver.class.php	2009-05-21 01:18:26.000000000 -0400
@@ -542,7 +542,19 @@
         $cnt = count($header);
         $hdr_s = '';
         for ($i = 0 ; $i < $cnt ; $i++)    {
-            $hdr_s .= $this->foldLine($header[$i], 78);
+          /*
+           * FIXME: Leave some name fields (filename, username) as they
+           * are, for now. If you want to fold these fields,
+           *
+           * 1) Count columns with base64 encoded chars, and
+           * 2) Split RAW text (before encoding), and
+           * 3) encode each splitted RAW texts.
+           */
+          if (strstr($header[$i], 'name') === false) {
+             $hdr_s .= $this->foldLine($header[$i], 78);
+          } else {
+              $hdr_s .= $header[$i];
+          }
         }
         $header = $hdr_s;
         $header .= $rn; /* One blank line to separate mimeheader and body-entity */
@@ -773,6 +785,7 @@
             case 'Cc':
             case 'Bcc':
             case 'From':
+            case 'Subject': // Prevent from base64-folding corruption.
                 $hdr_s .= $header[$i];
                 break;
             default: $hdr_s .= $this->foldLine($header[$i], 78); break;
