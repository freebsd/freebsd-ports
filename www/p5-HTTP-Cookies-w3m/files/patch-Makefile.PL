--- Makefile.PL.orig	2006-05-24 21:24:04.000000000 +0900
+++ Makefile.PL	2010-07-25 02:37:50.000000000 +0900
@@ -4,7 +4,7 @@
 author('Kazuhiro Osawa <ko@yappo.ne.jp>');
 all_from('lib/HTTP/Cookies/w3m.pm');
 
-build_requires(Test::More => 0.42);
+build_requires('Test::More' => 0.42);
 
 auto_include;
 auto_install;
