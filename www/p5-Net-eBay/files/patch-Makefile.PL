--- Makefile.PL.orig	Mon Sep 11 23:04:42 2006
+++ Makefile.PL	Wed Nov  1 10:16:38 2006
@@ -8,10 +8,6 @@
               VERSION_FROM        => 'lib/Net/eBay.pm',
               ABSTRACT            => 'XML based communication with eBay API',
               PL_FILES            => {},
-              EXE_FILES           => [ 'ebay-official-time.pl', 'ebay-validate-test-user.pl',
-                                       'ebay-get-categories.pl', 'ebay-add-item.pl', 'ebay-search.pl',
-                                       'ebay-revise-item.pl'
-                                     ],
               PREREQ_PM => {
                             'Test::More' => 0,
                             'XML::Simple' => 0,
