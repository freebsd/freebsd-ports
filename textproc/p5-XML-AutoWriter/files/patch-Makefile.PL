$FreeBSD$

--- Makefile.PL.orig	2012-12-23 11:07:17.511361339 +0900
+++ Makefile.PL	2012-12-23 11:09:35.165438990 +0900
@@ -9,7 +9,6 @@
 build_requires => 'Test';
 build_requires => 'IO::File';
 
-auto_set_repository;
 auto_manifest;
 auto_install;
 WriteAll;
