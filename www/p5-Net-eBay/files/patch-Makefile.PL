--- Makefile.PL.orig	Thu Mar 15 22:25:32 2007
+++ Makefile.PL	Sat Aug 25 19:00:31 2007
@@ -8,10 +8,7 @@ WriteMakefile(
               VERSION_FROM        => 'lib/Net/eBay.pm',
               ABSTRACT            => 'XML based communication with eBay API',
               PL_FILES            => {},
-              EXE_FILES           => [ 'ebay-official-time.pl', 'ebay-validate-test-user.pl',
-                                       'ebay-get-categories.pl', 'ebay-add-item.pl', 'ebay-search.pl',
-                                       'ebay-revise-item.pl', 'ebay-get-item.pl'
-                                     ],
+
               PREREQ_PM => {
                             'Test::More' => 0,
                             'XML::Simple' => 0,
