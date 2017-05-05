--- tools/gn/bootstrap/bootstrap.py.orig	2017-04-24 14:40:24 UTC
+++ tools/gn/bootstrap/bootstrap.py
@@ -23,6 +23,7 @@ import os
 import shutil
 import subprocess
 import sys
+import platform
 import tempfile
 
 BOOTSTRAP_DIR = os.path.dirname(os.path.abspath(__file__))
@@ -31,8 +32,9 @@ SRC_ROOT = os.path.dirname(os.path.dirna
 
 is_win = sys.platform.startswith('win')
 is_linux = sys.platform.startswith('linux')
+is_bsd = platform.system().lower().endswith('bsd')
 is_mac = sys.platform.startswith('darwin')
-is_posix = is_linux or is_mac
+is_posix = is_linux or is_mac or is_bsd
 
 def check_call(cmd, **kwargs):
   logging.debug('Running: %s', ' '.join(cmd))
@@ -625,6 +627,40 @@ def write_gn_ninja(path, root_gen_dir, o
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
+        'base/nix/xdg_util.cc',
+        'base/process/memory_stubs.cc',
+        #'base/process/internal_linux.cc',
+        'base/process/process_handle_' + platform.system().lower() + '.cc',
+        'base/process/process_iterator_' + platform.system().lower() + '.cc',
+        # 'base/process/process_linux.cc',
+        'base/process/process_metrics_'+ platform.system().lower() + '.cc',
+        'base/strings/sys_string_conversions_posix.cc',
+        'base/sys_info_' + platform.system().lower() + '.cc',
+        'base/threading/platform_thread_' + platform.system().lower() + '.cc',
+        # 'base/trace_event/malloc_dump_provider.cc',
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
