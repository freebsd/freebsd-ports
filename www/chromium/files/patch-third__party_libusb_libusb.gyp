--- third_party/libusb/libusb.gyp.orig	2016-05-20 17:19:03 UTC
+++ third_party/libusb/libusb.gyp
@@ -1,4 +1,4 @@
-# Copyright (c) 2012 The Chromium Authors. All rights reserved.
+# Copyright 2013 The Chromium Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
 
@@ -6,133 +6,29 @@
   'targets': [
     {
       'target_name': 'libusb',
-      'type': 'static_library',
-      'sources': [
-        'src/config.h',
-        'src/libusb/core.c',
-        'src/libusb/descriptor.c',
-        'src/libusb/hotplug.c',
-        'src/libusb/hotplug.h',
-        'src/libusb/interrupt.c',
-        'src/libusb/interrupt.h',
-        'src/libusb/io.c',
-        'src/libusb/libusb.h',
-        'src/libusb/libusbi.h',
-        'src/libusb/strerror.c',
-        'src/libusb/sync.c',
-        'src/libusb/version.h',
-        'src/libusb/version_nano.h',
-      ],
+      'type': 'none',
       'variables': {
-        'clang_warning_flags': [
-          # guid_eq in windows_usb.c is unused.
-          '-Wno-unused-function',
+        'headers_root_path': 'src/libusb',
+        'header_filenames': [
+          'libusb.h',
         ],
       },
-      'include_dirs': [
-        'src',
-        'src/libusb',
-        'src/libusb/os',
+      'includes': [
+        '../../build/shim_headers.gypi',
       ],
       'direct_dependent_settings': {
-        'include_dirs': [
-          'src/libusb',
+        'cflags': [
+          '<!@(pkg-config --cflags libusb-1.0)',
         ],
-      },
-      'conditions': [
-        ['OS=="linux" or OS=="mac"', {
-          'sources': [
-            'src/libusb/os/poll_posix.c',
-            'src/libusb/os/poll_posix.h',
-            'src/libusb/os/threads_posix.c',
-            'src/libusb/os/threads_posix.h',
-          ],
-          'defines': [
-            'DEFAULT_VISIBILITY=',
-            'HAVE_GETTIMEOFDAY=1',
-            'HAVE_POLL_H=1',
-            'HAVE_SYS_TIME_H=1',
-            'LIBUSB_DESCRIBE="1.0.16"',
-            'POLL_NFDS_TYPE=nfds_t',
-            'THREADS_POSIX=1',
-          ],
-        }],
-        ['OS=="linux"', {
-          'sources': [
-            'src/libusb/os/linux_usbfs.c',
-            'src/libusb/os/linux_usbfs.h',
-          ],
-          'defines': [
-            'OS_LINUX=1',
-            '_GNU_SOURCE=1',
-          ],
-        }],
-        ['chromeos==1', {
-          'defines': [
-            'USBI_TIMERFD_AVAILABLE',
-          ]
-        }],
-        ['use_udev==1', {
-          'sources': [
-            'src/libusb/os/linux_udev.cc',
-          ],
-          'defines': [
-            'HAVE_LIBUDEV=1',
-            'USE_UDEV=1',
-          ],
-          'dependencies': [
-            '../../device/udev_linux/udev.gyp:udev_linux',
-          ],
-          'include_dirs': [
-            '../..',
-          ],
-        }],
-        ['OS=="linux" and use_udev==0', {
-          'sources': [
-            'src/libusb/os/linux_netlink.c',
-          ],
-          'defines': [
-            'HAVE_LINUX_NETLINK_H',
-          ],
-          'conditions': [
-            ['clang==1', {
-              'cflags': [
-                '-Wno-pointer-sign',
-              ]
-            }]
-          ],
-        }],
-        ['OS=="mac"', {
-          'sources': [
-            'src/libusb/os/darwin_usb.c',
-            'src/libusb/os/darwin_usb.h',
-          ],
-          'defines': [
-            'OS_DARWIN=1',
-          ],
-        }],
-        ['OS=="win"', {
-          'sources': [
-            'src/libusb/os/poll_windows.c',
-            'src/libusb/os/poll_windows.h',
-            'src/libusb/os/threads_windows.c',
-            'src/libusb/os/threads_windows.h',
-            'src/libusb/os/windows_common.h',
-            'src/libusb/os/windows_usb.c',
-            'src/libusb/os/windows_usb.h',
-            'src/msvc/config.h',
-            'src/msvc/inttypes.h',
-            'src/msvc/stdint.h',
-          ],
-          'include_dirs!': [
-            'src',
+        'link_settings': {
+          'ldflags': [
+            '<!@(pkg-config --libs-only-L --libs-only-other libusb-1.0)',
           ],
-          'include_dirs': [
-            'src/msvc',
+          'libraries': [
+            '<!@(pkg-config --libs-only-l libusb-1.0)',
           ],
-          'msvs_disabled_warnings': [ 4267 ],
-        }],
-      ],
+        },
+      },
     },
   ],
 }
