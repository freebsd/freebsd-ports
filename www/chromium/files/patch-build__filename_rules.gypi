--- build/filename_rules.gypi.orig	2014-10-10 08:54:09 UTC
+++ build/filename_rules.gypi
@@ -85,7 +85,7 @@
     ['<(use_aura)==0 or OS!="win" or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_aurawin\\.(h|cc)$'] ]
     }],
-    ['<(use_aura)==0 or OS!="linux" or >(nacl_untrusted_build)==1', {
+    ['<(use_aura)==0 or (OS!="linux" and OS!="openbsd" and OS!="freebsd") or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_auralinux\\.(h|cc)$'] ]
     }],
     ['<(use_ash)==0 or >(nacl_untrusted_build)==1', {
