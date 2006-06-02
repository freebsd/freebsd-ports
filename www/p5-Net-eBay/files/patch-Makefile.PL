--- Makefile.PL.orig	Sat May 27 17:51:15 2006
+++ Makefile.PL	Sat May 27 17:52:00 2006
@@ -8,9 +8,7 @@ WriteMakefile(
               VERSION_FROM        => 'lib/Net/eBay.pm',
               ABSTRACT            => 'XML based communication with eBay API',
               PL_FILES            => {},
-              EXE_FILES           => [ 'ebay-official-time.pl', 'ebay-validate-test-user.pl',
-                                       'ebay-get-categories.pl', 'ebay-add-item.pl', 'ebay-search.pl'
-                                     ],
+
               PREREQ_PM => {
                             'Test::More' => 0,
                             'XML::Simple' => 0,
