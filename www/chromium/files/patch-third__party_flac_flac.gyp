--- third_party/flac/flac.gyp.orig	2016-05-20 17:19:03 UTC
+++ third_party/flac/flac.gyp
@@ -1,4 +1,4 @@
-# Copyright (c) 2011 The Chromium Authors. All rights reserved.
+# Copyright 2013 The Chromium Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
 
@@ -6,85 +6,32 @@
   'targets': [
     {
       'target_name': 'libflac',
-      'product_name': 'flac',
-      'type': 'static_library',
-      'sources': [
-        'include/FLAC/all.h',
-        'include/FLAC/assert.h',
-        'include/FLAC/callback.h',
-        'include/FLAC/export.h',
-        'include/FLAC/format.h',
-        'include/FLAC/metadata.h',
-        'include/FLAC/ordinals.h',
-        'include/FLAC/stream_decoder.h',
-        'include/FLAC/stream_encoder.h',
-        'include/share/alloc.h',
-        'src/libFLAC/alloc.c',
-        'src/libFLAC/bitmath.c',
-        'src/libFLAC/bitreader.c',
-        'src/libFLAC/bitwriter.c',
-        'src/libFLAC/cpu.c',
-        'src/libFLAC/crc.c',
-        'src/libFLAC/fixed.c',
-        'src/libFLAC/float.c',
-        'src/libFLAC/format.c',
-        'src/libFLAC/lpc.c',
-        'src/libFLAC/md5.c',
-        'src/libFLAC/memory.c',
-        'src/libFLAC/stream_decoder.c',
-        'src/libFLAC/stream_encoder.c',
-        'src/libFLAC/stream_encoder_framing.c',
-        'src/libFLAC/window.c',
-        'src/libFLAC/include/private/all.h',
-        'src/libFLAC/include/private/bitmath.h',
-        'src/libFLAC/include/private/bitreader.h',
-        'src/libFLAC/include/private/bitwriter.h',
-        'src/libFLAC/include/private/cpu.h',
-        'src/libFLAC/include/private/crc.h',
-        'src/libFLAC/include/private/fixed.h',
-        'src/libFLAC/include/private/float.h',
-        'src/libFLAC/include/private/format.h',
-        'src/libFLAC/include/private/lpc.h',
-        'src/libFLAC/include/private/md5.h',
-        'src/libFLAC/include/private/memory.h',
-        'src/libFLAC/include/private/metadata.h',
-        'src/libFLAC/include/private/stream_encoder_framing.h',
-        'src/libFLAC/include/private/window.h',
-        'src/libFLAC/include/protected/all.h',
-        'src/libFLAC/include/protected/stream_decoder.h',
-        'src/libFLAC/include/protected/stream_encoder.h',
-      ],
-      'defines': [
-        'FLAC__NO_DLL',
-        'FLAC__OVERFLOW_DETECT',
-        'VERSION="1.2.1"',
-      ],
-      'include_dirs': [
-        'include',
-        'src/libFLAC/include',
-      ],
-      'direct_dependent_settings': {
-        'defines': [
-          'FLAC__NO_DLL',
+      'type': 'none',
+      'variables': {
+        'headers_root_path': 'include',
+        'header_filenames': [
+          'FLAC/callback.h',
+          'FLAC/metadata.h',
+          'FLAC/assert.h',
+          'FLAC/export.h',
+          'FLAC/format.h',
+          'FLAC/stream_decoder.h',
+          'FLAC/stream_encoder.h',
+          'FLAC/ordinals.h',
+          'FLAC/all.h',
         ],
       },
-      'variables': {
-        'clang_warning_flags': [
-          # libflac converts between FLAC__StreamDecoderState and
-          # FLAC__StreamDecoderInitStatus a lot in stream_decoder.c.
-          '-Wno-conversion',
-          # libflac contains constants that are only used in certain
-          # compile-time cases, which triggers unused-const-variable warnings in
-          # other cases.
-          '-Wno-unused-const-variable',
+      'includes': [
+        '../../build/shim_headers.gypi',
+      ],
+      'link_settings': {
+        'ldflags': [
+          '<!@(pkg-config --libs-only-L --libs-only-other flac)',
+        ],
+        'libraries': [
+          '<!@(pkg-config --libs-only-l flac)',
         ],
       },
     },
   ],
 }
-
-# Local Variables:
-# tab-width:2
-# indent-tabs-mode:nil
-# End:
-# vim: set expandtab tabstop=2 shiftwidth=2:
