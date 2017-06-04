--- src/3rdparty/chromium/base/base.gypi.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/base/base.gypi
@@ -1006,9 +1006,14 @@
               'process/memory_stubs.cc',
             ],
             'sources/': [
+              ['exclude', '^debug/proc_maps_linux\\.cc$'],
+              ['exclude', '^files/file_path_watcher_fsevents\\.cc$'],
               ['exclude', '^files/file_path_watcher_linux\\.cc$'],
               ['exclude', '^files/file_path_watcher_stub\\.cc$'],
               ['exclude', '^files/file_util_linux\\.cc$'],
+              ['exclude', '^process/memory_linux\\.cc$'],
+              ['exclude', '^process/process_iterator_linux\\.cc$'],
+              ['exclude', '^process/process_metrics_linux\\.cc$'],
               ['exclude', '^process/process_linux\\.cc$'],
               ['exclude', '^sys_info_linux\\.cc$'],
             ],
