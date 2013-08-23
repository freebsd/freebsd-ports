--- base/base.gypi.orig	2013-08-09 22:05:55.000000000 +0300
+++ base/base.gypi	2013-08-17 20:58:50.000000000 +0300
@@ -838,6 +838,8 @@
               ['exclude', '^process_linux\\.cc$'],
               ['exclude', '^process_util_linux\\.cc$'],
               ['exclude', '^sys_info_linux\\.cc$'],
+              ['exclude', '^process/process_iterator_linux\\.cc$'],
+              ['exclude', '^process/process_metrics_linux\\.cc$'],
             ],
           }],
           ['<(chromeos)!=1 or >(nacl_untrusted_build)==1', {
