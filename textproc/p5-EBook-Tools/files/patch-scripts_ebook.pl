--- scripts/ebook.pl.orig	2014-10-01 22:27:01 UTC
+++ scripts/ebook.pl
@@ -92,7 +92,7 @@ my %opt = (
     'raw'         => 0,
     'subcategory' => undef,
     'tidy'        => 0,
-    'tidycmd'     => $config->val('helpers','tidy') || undef,
+    'tidycmd'     => $config->val('helpers','tidy') || 'tidy5',
     'tidysafety'  => $tidysafety,
     'title'       => undef,
     'verbose'     => $config->val('config','debug') || 0,
