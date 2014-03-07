--- lib/NetApp/Filer/Version.pm.orig	2013-12-30 22:00:16.000000000 +0800
+++ lib/NetApp/Filer/Version.pm	2013-12-30 22:00:33.000000000 +0800
@@ -40,7 +40,7 @@
         $string_of{$ident}	= $args{string};
 
         $args{string} =~
-            m{ NetApp \s+ Release \s+ (\S+) : \s+ (.*) }gmx ||
+            m{ NetApp \s+ Release \s+ (.+): \s+ (.+) }gmx ||
                    croak ("Invalid version string: $args{string}\n");
 
         $release_of{$ident}	= $1;
