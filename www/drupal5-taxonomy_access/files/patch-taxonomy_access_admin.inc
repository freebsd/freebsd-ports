--- taxonomy_access_admin.inc.orig	Sat Nov  4 22:50:38 2006
+++ taxonomy_access_admin.inc	Fri Feb 23 10:57:47 2007
@@ -127,7 +127,7 @@
         $form['taxonomy_access'][$vocab->vid]['default'][$grant] = array(
           '#type' => 'radios', 
           '#options' => $radios,
-          '#default_value' => $default[$vocab->vid][$grant],
+          '#default_value' => isset($default[$vocab->vid][$grant]) ? $default[$vocab->vid][$grant] : 0,
          );
       }
       foreach (array('create', 'list') as $grant) {
@@ -137,7 +137,7 @@
          );
         $form['taxonomy_access'][$vocab->vid]['default'][$grant] = array(
           '#type' => 'checkbox', 
-          '#default_value' => $default[$vocab->vid][$grant],
+          '#default_value' => isset($default[$vocab->vid][$grant]) ? $default[$vocab->vid][$grant] : 0,
          );
        }
 
@@ -150,13 +150,13 @@
             $form['taxonomy_access'][$vocab->vid]['term'][$term->tid][$grant] = array(
               '#type' => 'radios', 
               '#options' => $radios,
-              '#default_value' => $perm[$term->tid][$grant],
+              '#default_value' => isset($perm[$term->tid][$grant]) ? $perm[$term->tid][$grant] : 0,
              );
           }
           foreach (array('create', 'list') as $grant) {
             $form['taxonomy_access'][$vocab->vid]['term'][$term->tid][$grant] = array (
               '#type' => 'checkbox', 
-              '#default_value' => $perm[$term->tid][$grant],
+              '#default_value' => isset($perm[$term->tid][$grant]) ? $perm[$term->tid][$grant] : 0,
              );
           }
         }
