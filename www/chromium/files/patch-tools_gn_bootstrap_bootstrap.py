--- tools/gn/bootstrap/bootstrap.py.orig	2017-08-03 00:05:40.000000000 +0200
+++ tools/gn/bootstrap/bootstrap.py	2017-08-09 23:59:54.024577000 +0200
@@ -23,6 +23,7 @@
 import shutil
 import subprocess
 import sys
+import platform
 import tempfile
 
 BOOTSTRAP_DIR = os.path.dirname(os.path.abspath(__file__))
@@ -31,9 +32,10 @@
 
 is_win = sys.platform.startswith('win')
 is_linux = sys.platform.startswith('linux')
+is_bsd = platform.system().lower().endswith('bsd')
 is_mac = sys.platform.startswith('darwin')
 is_aix = sys.platform.startswith('aix')
-is_posix = is_linux or is_mac or is_aix
+is_posix = is_linux or is_mac or is_aix or is_bsd
 
 def check_call(cmd, **kwargs):
   logging.debug('Running: %s', ' '.join(cmd))
@@ -627,7 +629,7 @@
         'cflags': cflags + ['-DHAVE_CONFIG_H'],
     }
 
-  if is_linux or is_aix:
+  if is_linux or is_aix or is_bsd:
     ldflags.extend(['-pthread'])
 
     static_libraries['xdg_user_dirs'] = {
@@ -642,16 +644,45 @@
         'base/memory/shared_memory_tracker.cc',
         'base/nix/xdg_util.cc',
         'base/process/internal_linux.cc',
-        'base/process/memory_linux.cc',
+        #'base/process/memory_linux.cc',
         'base/process/process_handle_linux.cc',
         'base/process/process_info_linux.cc',
-        'base/process/process_iterator_linux.cc',
-        'base/process/process_linux.cc',
-        'base/process/process_metrics_linux.cc',
+        #'base/process/process_iterator_linux.cc',
+        #'base/process/process_linux.cc',
+        #'base/process/process_metrics_linux.cc',
         'base/strings/sys_string_conversions_posix.cc',
-        'base/sys_info_linux.cc',
+        #'base/sys_info_linux.cc',
         'base/threading/platform_thread_linux.cc',
     ])
+    if is_bsd:
+        libs.extend(['-lexecinfo', '-lkvm'])
+        ldflags.extend(['-pthread'])
+    
+    static_libraries['xdg_user_dirs'] = {
+        'sources': [
+            'base/third_party/xdg_user_dirs/xdg_user_dir_lookup.cc',
+        ],
+        'tool': 'cxx',
+    }
+    static_libraries['base']['sources'].extend([
+        'base/allocator/allocator_shim.cc',
+        'base/allocator/allocator_shim_default_dispatch_to_glibc.cc',
+        'base/process/process_handle_' + platform.system().lower() + '.cc',
+        'base/process/process_iterator_' + platform.system().lower() + '.cc',
+        'base/process/process_metrics_'+ platform.system().lower() + '.cc',
+        'base/sys_info_' + platform.system().lower() + '.cc',
+        'base/task_scheduler/environment_config.cc',
+    ])
+    static_libraries['libevent']['include_dirs'].extend([
+        os.path.join(SRC_ROOT, 'base', 'third_party', 'libevent', 'freebsd')
+    ])
+    static_libraries['libevent']['sources'].extend([
+        'base/third_party/libevent/kqueue.c',
+    ])
+
+    # Suppressing warnings
+    cflags.extend(['-Wno-deprecated-register', '-Wno-parentheses-equality'])
+
     if is_linux:
       static_libraries['base']['sources'].extend([
         'base/allocator/allocator_shim.cc',
@@ -663,17 +694,6 @@
       ])
       static_libraries['libevent']['sources'].extend([
          'base/third_party/libevent/epoll.c',
-      ])
-    else:
-      libs.extend(['-lrt'])
-      static_libraries['base']['sources'].extend([
-          'base/process/internal_aix.cc'
-      ])
-      static_libraries['libevent']['include_dirs'].extend([
-          os.path.join(SRC_ROOT, 'base', 'third_party', 'libevent', 'aix')
-      ])
-      static_libraries['libevent']['include_dirs'].extend([
-          os.path.join(SRC_ROOT, 'base', 'third_party', 'libevent', 'compat')
       ])
 
   if is_mac:
