--- functions/imap_messages.php.orig    Sun Feb 12 20:21:50 2006
+++ functions/imap_messages.php Mon Jan 22 20:14:11 2007
@@ -923,7 +923,7 @@
     if ($read) {
         if (preg_match('/.+FLAGS\s\((.*)\)\s/AUi',$read[0],$regs)) {
             if (trim($regs[1])) {
-                $flags = preg_split('/ /', $regs[1],-1,'PREG_SPLIT_NI_EMPTY');
+                $flags = preg_split('/ /', $regs[1],-1,PREG_SPLIT_NO_EMPTY);
             }
         }
     } else {

