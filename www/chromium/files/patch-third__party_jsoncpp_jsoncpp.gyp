--- third_party/jsoncpp/jsoncpp.gyp.orig	2016-05-20 17:19:03 UTC
+++ third_party/jsoncpp/jsoncpp.gyp
@@ -1,21 +1,39 @@
-# Copyright (c) 2012 The Chromium Authors. All rights reserved.
+# Copyright 2013 The Chromium Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
 
 {
-  'includes': [
-    'jsoncpp.gypi',
-  ],
   'targets': [
     {
       'target_name': 'jsoncpp',
-      'type': 'static_library',
-    },
+      'type': 'none',
+      'variables': {
+        'headers_root_path': 'source/include',
+        'header_filenames': [
+          'json/assertions.h',
+          'json/autolink.h',
+          'json/config.h',
+          'json/features.h',
+          'json/forwards.h',
+          'json/json.h',
+          'json/reader.h',
+          'json/value.h',
+          'json/writer.h',
+        ],
+      },
+      'includes': [
+        '../../build/shim_headers.gypi',
+      ],
+      'direct_dependent_settings': {
+        'include_dirs': [
+          '/usr/include/jsoncpp',
+        ],
+      },
+      'link_settings': {
+        'libraries': [
+          '-ljsoncpp',
+        ],
+      },
+    }
   ],
 }
-
-# Local Variables:
-# tab-width:2
-# indent-tabs-mode:nil
-# End:
-# vim: set expandtab tabstop=2 shiftwidth=2:
