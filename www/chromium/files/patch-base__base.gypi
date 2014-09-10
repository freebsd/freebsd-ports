--- ./base/base.gypi.orig	2014-08-20 21:02:42.000000000 +0200
+++ ./base/base.gypi	2014-08-22 18:33:25.000000000 +0200
@@ -942,11 +942,16 @@
               'process/memory_stubs.cc',
             ],
             'sources/': [
+              ['exclude', '^debug/proc_maps_linux\\.cc$'],
               ['exclude', '^files/file_path_watcher_linux\\.cc$'],
-              ['exclude', '^files/file_path_watcher_stub\\.cc$'],
               ['exclude', '^file_util_linux\\.cc$'],
+              ['exclude', '^process/memory_linux\\.cc$'],
               ['exclude', '^process/process_linux\\.cc$'],
               ['exclude', '^sys_info_linux\\.cc$'],
+              ['exclude', '^process/process_iterator_linux\\.cc$'],
+              ['exclude', '^process/process_metrics_linux\\.cc$'],
+              ['exclude', '^files/file_path_watcher_fsevents\\.cc$'],
+              ['exclude', '^files/file_path_watcher_fsevents\\.h$'],
             ],
           }],
           # Remove all unnecessary files for build_nexe.py to avoid exceeding
