--- ./class/deliver/Deliver.class.php.orig	2010-08-03 16:33:49.000000000 -0400
+++ ./class/deliver/Deliver.class.php	2010-08-03 16:35:25.000000000 -0400
@@ -542,7 +542,19 @@
         $cnt = count($header);
         $hdr_s = '';
         for ($i = 0 ; $i < $cnt ; $i++)    {
-            $hdr_s .= $this->foldLine($header[$i]);
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
@@ -778,6 +790,7 @@
             case 'Cc':
             case 'Bcc':
             case 'From':
+	    case 'Subject': // Prevent from base64-folding corruption.
                 $hdr_s .= $header[$i];
                 break;
             default: $hdr_s .= $this->foldLine($header[$i]); break;
