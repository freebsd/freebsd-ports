--- inst/upgrade/1.8.9/fix_publish_status.pl.orig	Fri Jan 20 08:07:05 2006
+++ inst/upgrade/1.8.9/fix_publish_status.pl	Thu Feb  9 02:17:16 2006
@@ -6,12 +6,18 @@ use FindBin;
 use lib catdir $FindBin::Bin, updir, 'lib';
 use bric_upgrade qw(:all);
 
+# Later versions will have booleans instead of NUMERIC.
+my ($true, $false)
+    = test_column('story', 'publish_status', undef, undef, 'boolean')
+    ? qw(TRUE FALSE)
+    : qw( 1 0 );
+
 for my $thing (qw(story media)) {
     do_sql
         qq{UPDATE $thing
-           SET    publish_status = '1'
+           SET    publish_status = $true
            WHERE  published_version IS NOT NULL
-                  AND publish_status = '0'
+                  AND publish_status = $false
         },
 
         # We have no idea what version was actually published, so
@@ -19,7 +25,7 @@ for my $thing (qw(story media)) {
         qq{UPDATE $thing
            SET    published_version = current_version
            WHERE  published_version IS NULL
-                  AND publish_status = '1'
+                  AND publish_status = $true
         },
 
         # We don't know if it has been published since the first
@@ -39,7 +45,7 @@ for my $thing (qw(story media)) {
 
         # Remove the publish_status when there are no publish dates.
         qq{UPDATE $thing
-           SET    publish_status = '0'
+           SET    publish_status = $false
            WHERE  publish_date IS NULL
         },
     ;
