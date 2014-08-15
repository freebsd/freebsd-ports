--- ./build/filename_rules.gypi.orig	2014-08-12 21:02:52.000000000 +0200
+++ ./build/filename_rules.gypi	2014-08-13 09:56:56.000000000 +0200
@@ -85,7 +85,7 @@
     ['<(use_aura)==0 or OS!="win" or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_aurawin\\.(h|cc)$'] ]
     }],
-    ['<(use_aura)==0 or OS!="linux" or >(nacl_untrusted_build)==1', {
+    ['<(use_aura)==0 or (OS!="linux" and OS!="openbsd" and OS!="freebsd") or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_auralinux\\.(h|cc)$'] ]
     }],
     ['<(use_ash)==0 or >(nacl_untrusted_build)==1', {
