--- Makefile.PL.orig	Thu Mar 17 19:34:06 2005
+++ Makefile.PL	Thu Mar 17 19:34:20 2005
@@ -232,19 +232,7 @@
         COMPRESS => "gzip -9 -f ", 
     }, 
     MAN1PODS     => {}, 
-    MAN3PODS     => 
-    { 
-        map 
-        {
-            my $file = "lib/$_";
-            my $man = $_;
-            $man =~ s!\.(pm|pod)$!!;
-            $man =~ s!/!::!g;
-            $man = "blib/man3/${man}.3pm";
-            $file => $man;
-        } 
-        @manify
-    }, 
+    MAN3PODS     => {}, 
     PREREQ_PM    => { 'Compress::Zlib' => 1.0, }, 
     VERSION_FROM => $versionfile, 
 );
