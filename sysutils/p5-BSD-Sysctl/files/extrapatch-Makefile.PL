--- Makefile.PL.orig	2025-07-26 06:21:52 UTC
+++ Makefile.PL
@@ -51,13 +51,7 @@ WriteMakefile(
     PREREQ_PM     => {
         'XSLoader' => 0
     },
-    PM_FILTER     => 'perl -pe "if (/^\#include (.+)$$/) {		\
-					open FILE, \\$$1 or		\
-					    die \"open \\$$1\";		\
-					while (<FILE>) { print; };	\
-					close FILE;			\
-					next;				\
-				};"',
+    PM_FILTER     => q{perl -pe 'if (/^#include (.+)$$/) { open FILE, \\$$1 or die; while (<FILE>) { print; }; close FILE; next; };'},
     clean => {
         FILES => 'bsd-sysctl.h bsd-sysctl.ph',
     },
