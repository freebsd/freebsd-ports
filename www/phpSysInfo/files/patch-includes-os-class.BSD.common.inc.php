Index: includes/os/class.BSD.common.inc.php
==================================================================XRCS file: /cvsroot/phpsysinfo/phpsysinfo-dev/includes/os/class.BSD.common.inc.php,v
retrieving revision 1.4
diff -u -3 -r1.4 class.BSD.common.inc.php
--- includes/os/class.BSD.common.inc.php	4 Feb 2002 01:27:30 -0000	1.4
+++ includes/os/class.BSD.common.inc.php	17 Feb 2002 06:50:27 -0000
@@ -179,14 +179,17 @@
                 $results[$s]['model'] = $ar_buf[3];
                 $results[$s]['media'] = 'Hard Disk';
                 $results[$s]['capacity'] = $ar_buf[2] * 2048 * 1.049;
-            }
-            if (preg_match('/^(acd[0-9]): (.*) <(.*)> (.*)/', $buf, $ar_buf)) {
+            } else
+	    if (preg_match('/^(acd[0-9]): (.*) <(.*)> (.*)/', $buf, $ar_buf)) {
                 $s = $ar_buf[1];
                 $results[$s]['model'] = $ar_buf[3];
                 $results[$s]['media'] = 'CD-ROM';
             }
         }
-        return array_values(array_unique($results));
+        //return array_values(array_unique($results));
+	//1. more useful to have device names
+	//2. php 4.1.1 array_unique() deletes non-unique values.
+	return $results;
     }
 
     function memory ()
