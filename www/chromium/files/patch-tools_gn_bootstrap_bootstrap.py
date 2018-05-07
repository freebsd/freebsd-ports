--- tools/gn/bootstrap/bootstrap.py.orig	2017-12-23 20:11:27.769312000 +0100
+++ tools/gn/bootstrap/bootstrap.py	2017-12-23 20:28:42.756301000 +0100
@@ -32,9 +32,10 @@
 
 is_win = sys.platform.startswith('win')
 is_linux = sys.platform.startswith('linux')
+is_bsd = platform.system().lower().endswith('bsd')
 is_mac = sys.platform.startswith('darwin')
 is_aix = sys.platform.startswith('aix')
-is_posix = is_linux or is_mac or is_aix
+is_posix = is_linux or is_mac or is_aix or is_bsd
 
 def check_call(cmd, **kwargs):
   logging.debug('Running: %s', ' '.join(cmd))
@@ -576,7 +577,6 @@
       'base/trace_event/trace_log_constants.cc',
       'base/trace_event/tracing_agent.cc',
       'base/unguessable_token.cc',
-      'base/value_iterators.cc',
       'base/values.cc',
       'base/vlog.cc',
   ])
@@ -633,6 +633,44 @@
         'cflags': cflags + ['-DHAVE_CONFIG_H'],
     }
 
+  if is_bsd:
+    libs.extend(['-lexecinfo', '-lkvm'])
+    ldflags.extend(['-pthread'])
+    include_dirs += ["/usr/local/include"]
+
+    static_libraries['xdg_user_dirs'] = {
+        'sources': [
+            'base/third_party/xdg_user_dirs/xdg_user_dir_lookup.cc',
+        ],
+        'tool': 'cxx',
+    }
+    static_libraries['base']['sources'].extend([
+        'base/memory/shared_memory_handle_posix.cc',
+        'base/memory/shared_memory_posix.cc',
+        'base/nix/xdg_util.cc',
+        'base/process/memory_stubs.cc',
+        'base/process/process_info_linux.cc',
+        'base/process/internal_linux.cc',
+        'base/process/process_handle_freebsd.cc',
+        'base/process/process_metrics_freebsd.cc',
+        'base/strings/sys_string_conversions_posix.cc',
+        'base/sys_info_freebsd.cc',
+        'base/threading/platform_thread_linux.cc',
+        'base/synchronization/waitable_event_posix.cc',
+        'base/time/time_exploded_posix.cc',
+        'base/time/time_now_posix.cc',
+        'base/value_iterators.cc',
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
   if is_linux or is_aix:
     ldflags.extend(['-pthread'])
 
@@ -671,17 +709,6 @@
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
