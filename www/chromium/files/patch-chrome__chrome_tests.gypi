--- chrome/chrome_tests.gypi.orig	2011-05-06 12:03:42.000000000 +0300
+++ chrome/chrome_tests.gypi	2011-06-04 00:50:16.731405108 +0300
@@ -191,7 +191,7 @@
         '../content/common/notification_observer_mock.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -245,7 +245,7 @@
             'chrome.gyp:crash_service',  # run time dependency
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -330,7 +330,7 @@
         'test/unit/run_all_unittests.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   test/unit/run_all_unittests.cc
@@ -376,7 +376,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
@@ -449,14 +449,14 @@
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
@@ -657,12 +657,12 @@
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
@@ -837,7 +837,7 @@
         'test/webdriver/commands/webelement_commands.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -1946,7 +1946,7 @@
             ['exclude', '^browser/ui/webui/chromeos/login'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'conditions': [
             ['gcc_version==44', {
               # Avoid gcc 4.4 strict aliasing issues in stl_tree.h when
@@ -1983,7 +1983,7 @@
           'sources!': [
             'browser/printing/print_job_unittest.cc',
           ],
-        }, { # else: OS != "linux"
+        }, { # else: OS != "linux" and OS != "freebsd"
           'sources!': [
             'browser/ui/gtk/tabs/tab_renderer_gtk_unittest.cc',
             'browser/renderer_host/gtk_key_bindings_handler_unittest.cc',
@@ -2481,7 +2481,7 @@
             '../content/browser/child_process_security_policy_browsertest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -2650,7 +2650,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2751,7 +2751,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -2788,7 +2788,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2825,7 +2825,7 @@
         'test/tab_switching/tab_switching_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2859,7 +2859,7 @@
         'test/memory_test/memory_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -3025,7 +3025,7 @@
             'browser/sync/util/data_encryption_unittest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -3139,7 +3139,7 @@
         'test/data/resource.rc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3285,7 +3285,7 @@
           # See comments about "xcode_settings" elsewhere in this file.
           'xcode_settings': {'OTHER_LDFLAGS': ['-Wl,-ObjC']},
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3399,7 +3399,7 @@
             'test/perf/url_parse_perftest.cc',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'dependencies': [
                 '../build/linux/system.gyp:gtk',
                 '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -3780,7 +3780,7 @@
                 '../courgette/courgette.gyp:courgette_unittests',
                 'browser_tests',
                 ]}],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'dependencies': [
                 # Reason for disabling UI tests on non-Linux above.
                 'ui_tests',
