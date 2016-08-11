--- third_party/re2/re2.gyp.orig	2016-05-20 17:19:03 UTC
+++ third_party/re2/re2.gyp
@@ -1,84 +1,37 @@
-# Copyright 2014 The Chromium Authors. All rights reserved.
+# Copyright 2013 The Chromium Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
 
 {
-  'variables': {
-    'build_for_tool%': '',
-  },
   'targets': [
     {
       'target_name': 're2',
-      'type': 'static_library',
-      'include_dirs': [
-        'src',
-        '<(DEPTH)',
-      ],
-      'direct_dependent_settings': {
-        'include_dirs': [
-          'src',
-          '<(DEPTH)',
+      'type': 'none',
+      'variables': {
+        'headers_root_path': '.',
+        'header_filenames': [
+          're2/filtered_re2.h',
+          're2/re2.h',
+          're2/set.h',
+          're2/stringpiece.h',
+          're2/variadic_function.h',
+        ],
+        'shim_generator_additional_args': [
+          # Chromium copy of re2 is patched to rename POSIX to POSIX_SYNTAX
+          # because of collision issues that break the build.
+          # Upstream refuses to make changes:
+          # http://code.google.com/p/re2/issues/detail?id=73 .
+          '--define', 'POSIX=POSIX_SYNTAX',
         ],
       },
-      'sources': [
-        'src/re2/bitstate.cc',
-        'src/re2/compile.cc',
-        'src/re2/dfa.cc',
-        'src/re2/filtered_re2.cc',
-        'src/re2/filtered_re2.h',
-        'src/re2/mimics_pcre.cc',
-        'src/re2/nfa.cc',
-        'src/re2/onepass.cc',
-        'src/re2/parse.cc',
-        'src/re2/perl_groups.cc',
-        'src/re2/prefilter.cc',
-        'src/re2/prefilter.h',
-        'src/re2/prefilter_tree.cc',
-        'src/re2/prefilter_tree.h',
-        'src/re2/prog.cc',
-        'src/re2/prog.h',
-        'src/re2/re2.cc',
-        'src/re2/re2.h',
-        'src/re2/regexp.cc',
-        'src/re2/regexp.h',
-        'src/re2/set.cc',
-        'src/re2/set.h',
-        'src/re2/simplify.cc',
-        'src/re2/stringpiece.cc',
-        'src/re2/stringpiece.h',
-        'src/re2/tostring.cc',
-        'src/re2/unicode_casefold.cc',
-        'src/re2/unicode_casefold.h',
-        'src/re2/unicode_groups.cc',
-        'src/re2/unicode_groups.h',
-        'src/re2/variadic_function.h',
-        'src/re2/walker-inl.h',
-        'src/util/atomicops.h',
-        'src/util/flags.h',
-        'src/util/hash.cc',
-        'src/util/logging.cc',
-        'src/util/logging.h',
-        'src/util/mutex.h',
-        'src/util/rune.cc',
-        'src/util/sparse_array.h',
-        'src/util/sparse_set.h',
-        'src/util/stringprintf.cc',
-        'src/util/strutil.cc',
-        'src/util/utf.h',
-        'src/util/util.h',
-        'src/util/valgrind.cc',
-        'src/util/valgrind.h',
+      'includes': [
+        '../../build/shim_headers.gypi',
       ],
-      'conditions': [
-        ['build_for_tool=="drmemory"', {
-          # Treat builds for Dr. Memory as builds for MSAN to prevent false
-          # positives created by lazily initialized memory.
-          # See crbug.com/568119#3 .
-          'defines': [
-            'MEMORY_SANITIZER'
-          ],
-        }],
-      ]
-    },
+      'link_settings': {
+        'libraries': [
+          '-lre2',
+        ],
+      },
+    }
   ],
 }
