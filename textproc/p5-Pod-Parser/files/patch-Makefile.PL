--- Makefile.PL.orig	2012-05-02 01:15:22.779158978 +0800
+++ Makefile.PL	2012-05-02 01:16:22.355173981 +0800
@@ -83,7 +83,6 @@
     PREREQ_PM    => \%prereq,
     ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
        (ABSTRACT   => 'Modules for parsing/translating POD format documents',
-        AUTHOR     => [ 'Brad Appleton <bradapp@enteract.com>',
-                        'Marek Rouchal <marekr@cpan.org>' ] ) : ()),
+        AUTHOR     => 'Brad Appleton <bradapp@enteract.com>, Marek Rouchal <marekr@cpan.org>' ) : ()),
 );
 
