--- inst/upgrade/1.8.9/update_publish_status_check.pl.orig	Fri Jan 20 08:07:05 2006
+++ inst/upgrade/1.8.9/update_publish_status_check.pl	Thu Feb  9 02:17:16 2006
@@ -9,27 +9,46 @@ use bric_upgrade qw(:all);
 # Skip it for later versions of Bricolage.
 exit unless test_constraint 'story', 'ck_story__publish_status';
 
+# Later versions will have booleans instead of NUMERIC.
+my $bool = test_column('story', 'publish_status', undef, undef, 'boolean');
+
 for my $thing (qw(story media)) {
     do_sql
         qq{ALTER TABLE $thing DROP CONSTRAINT ck_$thing\__publish_status},
 
-        qq{ALTER TABLE $thing
-           ADD CONSTRAINT ck_$thing\__publish_status CHECK (
-               publish_status IN (0,1)
-               AND (
+        ($bool
+         ?  qq{ALTER TABLE $thing
+               ADD CONSTRAINT ck_$thing\__publish_status CHECK (
                    (
-                       publish_status = 0
+                       publish_status = FALSE
                        AND publish_date IS NULL
                        AND first_publish_date IS NULL
                    )
                    OR (
-                       publish_status = 1
+                       publish_status = TRUE
                        AND publish_date IS NOT NULL
                        AND first_publish_date IS NOT NULL
                    )
                )
-           )
-        },
+            }
+         :  qq{ALTER TABLE $thing
+               ADD CONSTRAINT ck_$thing\__publish_status CHECK (
+                   publish_status IN (0, 1)
+                   AND (
+                       (
+                           publish_status = 0
+                           AND publish_date IS NULL
+                           AND first_publish_date IS NULL
+                       )
+                       OR (
+                           publish_status = 1
+                           AND publish_date IS NOT NULL
+                           AND first_publish_date IS NOT NULL
+                       )
+                   )
+               )
+            }
+        )
     ;
 }
 
