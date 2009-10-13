--- Makefile.PL.orig	2009-10-13 23:00:47.267814042 +0900
+++ Makefile.PL	2009-10-13 23:00:55.231925535 +0900
@@ -1,6 +1,5 @@
 use inc::Module::Install;
 name 'PSGI';
 version '1.00';
-all_from 'PSGI.pm';
 auto_set_repository;
 WriteAll;
