--- Makefile.PL~	Tue Feb  4 19:02:23 2003
+++ Makefile.PL	Tue Feb  4 19:02:34 2003
@@ -9,6 +9,5 @@
 	    ('ABSTRACT' => 'Expand tabs and do simple line wrapping',
 	     'AUTHOR'	=> 'David Muir Sharnoff <muir@idiom.com>') : ()),
 	'dist' => { COMPRESS=>"gzip", SUFFIX=>"gz" },
-	'INSTALLDIRS'	=> 'perl',
 	);
 
