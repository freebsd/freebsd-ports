--- t/lib/__title_tests.pm.orig	Thu Feb 17 22:02:22 2005
+++ t/lib/__title_tests.pm	Sun Feb  5 21:46:10 2006
@@ -34,6 +34,9 @@
 
 $VERSION	= '0.4';  # to match Text::Capitalize version
 
+use POSIX qw(locale_h);                                                                     
+setlocale(LC_ALL, 'fr_FR.ISO8859-1');
+
 # Some possibly useful test case strings.
 # The %expect_* series below is what's actually used by "make test"
 
