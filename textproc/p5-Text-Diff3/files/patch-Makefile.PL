--- Makefile.PL.orig	Wed Oct 19 09:48:47 2005
+++ Makefile.PL	Mon May 29 14:18:42 2006
@@ -1,10 +1,9 @@
-use 5.008005;
-use ExtUtils::MakeMaker;
-WriteMakefile(
-    NAME              => 'Text::Diff3',
-    VERSION_FROM      => 'lib/Text/Diff3.pm',
-    PREREQ_PM         => {},
-    ($] >= 5.005 ?
-      (ABSTRACT_FROM  => 'lib/Text/Diff3.pm',
-       AUTHOR         => 'MIZUTANI Tociyuki <tociyuki@gmail.com>') : ()),
-);
+use ExtUtils::MakeMaker;
+WriteMakefile(
+    NAME              => 'Text::Diff3',
+    VERSION_FROM      => 'lib/Text/Diff3.pm',
+    PREREQ_PM         => {},
+    ($] >= 5.005 ?
+      (ABSTRACT_FROM  => 'lib/Text/Diff3.pm',
+       AUTHOR         => 'MIZUTANI Tociyuki <tociyuki@gmail.com>') : ()),
+);
