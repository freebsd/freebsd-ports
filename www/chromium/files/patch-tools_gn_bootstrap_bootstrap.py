--- tools/gn/bootstrap/bootstrap.py.orig	2017-06-05 21:03:29.000000000 +0200
+++ tools/gn/bootstrap/bootstrap.py	2017-06-13 19:25:21.449012000 +0200
@@ -23,6 +23,7 @@
 import shutil
 import subprocess
 import sys
+import platform
 import tempfile
 
 BOOTSTRAP_DIR = os.path.dirname(os.path.abspath(__file__))
@@ -31,8 +32,9 @@
 
 is_win = sys.platform.startswith('win')
 is_linux = sys.platform.startswith('linux')
+is_bsd = platform.system().lower().endswith('bsd')
 is_mac = sys.platform.startswith('darwin')
-is_posix = is_linux or is_mac
+is_posix = is_linux or is_mac or is_bsd
 
 def check_call(cmd, **kwargs):
   logging.debug('Running: %s', ' '.join(cmd))
@@ -632,6 +634,40 @@
         'base/third_party/libevent/epoll.c',
     ])
 
+  if is_bsd:
+    libs.extend(['-lexecinfo', '-lkvm'])
+    ldflags.extend(['-pthread'])
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
+        'base/memory/shared_memory_posix.cc',
+        'base/memory/shared_memory_tracker.cc',
+        'base/nix/xdg_util.cc',
+        'base/process/internal_linux.cc',
+        'base/process/process_handle_' + platform.system().lower() + '.cc',
+        'base/process/process_iterator_' + platform.system().lower() + '.cc',
+        #'base/process/process_linux.cc',
+        'base/process/process_metrics_'+ platform.system().lower() + '.cc',
+        'base/strings/sys_string_conversions_posix.cc',
+        'base/sys_info_' + platform.system().lower() + '.cc',
+        'base/threading/platform_thread_linux.cc',
+        #'base/trace_event/malloc_dump_provider.cc',
+    ])
+    static_libraries['libevent']['include_dirs'].extend([
+        os.path.join(SRC_ROOT, 'base', 'third_party', 'libevent', 'freebsd')
+    ])
+    static_libraries['libevent']['sources'].extend([
+        'base/third_party/libevent/kqueue.c',
+    ])
+    # Suppressing warnings
+    cflags.extend(['-Wno-deprecated-register', '-Wno-parentheses-equality'])
 
   if is_mac:
     static_libraries['base']['sources'].extend([
