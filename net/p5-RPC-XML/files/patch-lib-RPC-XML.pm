--- lib/RPC/XML.pm.orig	2011-08-22 11:29:30.000000000 +0200
+++ lib/RPC/XML.pm	2013-04-23 10:28:19.780990362 +0200
@@ -258,6 +258,7 @@
                     $type = reftype $_;
                     die "Un-convertable reference: $type, cannot use\n";
                 }
+                $seenrefs->{$_}--;
             }
             # You have to check ints first, because they match the
             # next pattern (for doubles) too
