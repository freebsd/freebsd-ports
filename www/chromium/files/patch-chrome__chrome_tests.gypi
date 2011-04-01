--- chrome/chrome_tests.gypi.orig	2011-01-06 10:02:02.000000000 +0100
+++ chrome/chrome_tests.gypi	2011-01-09 21:00:16.000000000 +0100
@@ -141,7 +141,7 @@
         'test/unit/chrome_test_suite.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -191,7 +191,7 @@
         'test/ui/ui_test_suite.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -215,7 +215,7 @@
         'test/unit/run_all_unittests.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   test/unit/run_all_unittests.cc
@@ -261,7 +261,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
@@ -341,7 +341,7 @@
         'test/unit/chrome_test_suite.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -555,12 +555,12 @@
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
@@ -720,7 +720,7 @@
         'test/webdriver/commands/webdriver_command.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -1749,7 +1749,7 @@
             ['exclude', '^browser/chromeos/'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'conditions': [
             ['gcc_version==44', {
               # Avoid gcc 4.4 strict aliasing issues in stl_tree.h when
@@ -1786,7 +1786,7 @@
           'sources!': [
             'browser/printing/print_job_unittest.cc',
           ],
-        }, { # else: OS != "linux"
+        }, { # else: OS != "linux" and OS != "freebsd"
           'sources!': [
             'browser/gtk/tabs/tab_renderer_gtk_unittest.cc',
             'browser/renderer_host/gtk_key_bindings_handler_unittest.cc',
@@ -2265,7 +2265,7 @@
             'browser/renderer_host/test/render_view_host_manager_browsertest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -2428,7 +2428,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2529,7 +2529,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -2566,7 +2566,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2603,7 +2603,7 @@
         'test/tab_switching/tab_switching_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2637,7 +2637,7 @@
         'test/memory_test/memory_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2790,7 +2790,7 @@
             'browser/sync/util/data_encryption_unittest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -2908,7 +2908,7 @@
       ],
       'conditions': [
         # Plugin code.
-        ['OS=="linux" or OS=="win"', {
+        ['OS=="linux" or OS=="freebsd" or OS=="win"', {
           'dependencies': [
             'plugin',
            ],
@@ -2916,7 +2916,7 @@
             'plugin',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3143,7 +3143,7 @@
             'test/perf/url_parse_perftest.cc',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'dependencies': [
                 '../build/linux/system.gyp:gtk',
                 '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
