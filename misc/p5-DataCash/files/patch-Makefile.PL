--- Makefile.PL.orig	Mon Aug 13 15:03:10 2001
+++ Makefile.PL	Mon Aug 13 15:07:05 2001
@@ -52,12 +52,12 @@
 }
 
 WriteMakefile(
-    'NAME'	=> 'DataCash::External',
+    'NAME' => 'External',
     'VERSION_FROM' => 'DataCash/External.pm',
     'PREREQ_PM' => $deps,
-    'dist' => {
-		 COMPRESS => 'gzip',
-		 SUFFIX => 'gz',
-	 },
+    'PM' => { 'DataCash/External.pm' => '$(INST_LIBDIR)/DataCash/External.pm',
+	'datacash.pl' => '$(INST_LIBDIR)/DataCash/datacash.pl',
+	'File/KGlob.pm' => '$(INST_LIBDIR)/File/KGlob.pm',
+	'File/KGlob2RE.pm' => '$(INST_LIBDIR)/File/KGlob2RE.pm' }
  );
 
