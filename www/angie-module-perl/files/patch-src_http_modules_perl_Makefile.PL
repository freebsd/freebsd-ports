--- src/http/modules/perl/Makefile.PL.orig	2023-05-30 14:39:09 UTC
+++ src/http/modules/perl/Makefile.PL
@@ -13,7 +13,7 @@ WriteMakefile(
     ABSTRACT_FROM     => 'nginx.pm',     # retrieve abstract from module
     AUTHOR            => 'Igor Sysoev',
 
-    CCFLAGS           => "$ENV{NGX_PM_CFLAGS}",
+    CCFLAGS           => "$ENV{NGX_PM_CFLAGS} -Wno-compound-token-split-by-macro",
     OPTIMIZE          => '-O',
 
     LDDLFLAGS         => "$ENV{NGX_PM_LDFLAGS}",
