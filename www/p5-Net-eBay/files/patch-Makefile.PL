--- Makefile.PL.orig	2008-06-08 17:27:50.000000000 +0400
+++ Makefile.PL	2008-06-08 17:26:56.000000000 +0400
@@ -8,10 +8,6 @@ WriteMakefile(
               VERSION_FROM        => 'lib/Net/eBay.pm',
               ABSTRACT            => 'XML based communication with eBay API',
               PL_FILES            => {},
-              EXE_FILES           => [ 'ebay-official-time.pl', 'ebay-validate-test-user.pl',
-                                       'ebay-get-categories.pl', 'ebay-add-item.pl', 'ebay-search.pl',
-                                       'ebay-revise-item.pl', 'ebay-get-item.pl'
-                                     ],
               PREREQ_PM => {
                             'Test::More' => 0,
                             'XML::Simple' => 0,
