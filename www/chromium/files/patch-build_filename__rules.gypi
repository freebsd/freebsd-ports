--- build/filename_rules.gypi.orig	2016-04-08 16:02:06 UTC
+++ build/filename_rules.gypi
@@ -89,7 +89,7 @@
                     ['exclude', '_ashwin\\.(h|cc)$']
       ]
     }],
-    ['<(use_aura)==0 or OS!="linux" or >(nacl_untrusted_build)==1', {
+    ['<(use_aura)==0 or (OS!="linux" and OS!="openbsd" and OS!="freebsd") or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_auralinux\\.(h|cc)$'] ]
     }],
     ['<(use_ozone)==0 or >(nacl_untrusted_build)==1', {
