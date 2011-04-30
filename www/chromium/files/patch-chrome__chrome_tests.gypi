--- chrome/chrome_tests.gypi.orig	2011-04-16 19:33:32.144068169 +0300
+++ chrome/chrome_tests.gypi	2011-04-16 19:33:47.813071073 +0300
@@ -185,7 +185,7 @@
         '../content/common/notification_observer_mock.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -239,7 +239,7 @@
             'chrome.gyp:crash_service',  # run time dependency
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -279,7 +279,7 @@
         'test/unit/run_all_unittests.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   test/unit/run_all_unittests.cc
@@ -325,7 +325,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
@@ -398,14 +398,14 @@
         'test/unit/chrome_test_suite.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
         }],
-        ['OS=="linux" and toolkit_views==0', {
+        ['(OS=="linux" or OS=="freebsd") and toolkit_views==0', {
           'sources!': [
             # TODO(port)
             'browser/ui/views/bookmarks/bookmark_bar_view_test.cc',
@@ -606,12 +606,12 @@
             '../webkit/webkit.gyp:copy_npapi_test_plugin',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
-        }, { # else: OS != "linux"
+        }, { # else: OS != "linux" and OS != "freebsd"
           'sources!': [
             'browser/process_singleton_linux_uitest.cc',
           ],
@@ -782,7 +782,7 @@
         'test/webdriver/commands/webelement_commands.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -1893,7 +1893,7 @@
             ['exclude', '^browser/chromeos/'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'conditions': [
             ['gcc_version==44', {
               # Avoid gcc 4.4 strict aliasing issues in stl_tree.h when
@@ -1930,7 +1930,7 @@
           'sources!': [
             'browser/printing/print_job_unittest.cc',
           ],
-        }, { # else: OS != "linux"
+        }, { # else: OS != "linux" and OS != "freebsd"
           'sources!': [
             'browser/ui/gtk/tabs/tab_renderer_gtk_unittest.cc',
             'browser/renderer_host/gtk_key_bindings_handler_unittest.cc',
@@ -2420,7 +2420,7 @@
             '../content/browser/renderer_host/render_view_host_manager_browsertest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -2589,7 +2589,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2690,7 +2690,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -2727,7 +2727,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2764,7 +2764,7 @@
         'test/tab_switching/tab_switching_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2798,7 +2798,7 @@
         'test/memory_test/memory_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2961,7 +2961,7 @@
             'browser/sync/util/data_encryption_unittest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -3075,7 +3075,7 @@
       ],
       'conditions': [
         # Plugin code.
-        ['OS=="linux" or OS=="win"', {
+        ['OS=="linux" or OS=="freebsd" or OS=="win"', {
           'dependencies': [
             'plugin',
            ],
@@ -3083,7 +3083,7 @@
             'plugin',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3228,7 +3228,7 @@
           # See comments about "xcode_settings" elsewhere in this file.
           'xcode_settings': {'OTHER_LDFLAGS': ['-Wl,-ObjC']},
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3311,7 +3311,7 @@
             'test/perf/url_parse_perftest.cc',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'dependencies': [
                 '../build/linux/system.gyp:gtk',
                 '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
