--- third_party/chromium/src/build/common.gypi.orig	2017-10-07 00:10:16 UTC
+++ third_party/chromium/src/build/common.gypi
@@ -100,7 +100,7 @@
             ['OS=="win" or OS=="mac" or OS=="ios"', {
               'host_arch%': 'ia32',
             }, {
-              'host_arch%': '<!(python <(DEPTH)/build/linux/detect_host_arch.py)',
+              'host_arch%': '<!(python2.7 <(DEPTH)/build/linux/detect_host_arch.py)',
             }],
 
             # Embedded implies ozone.
@@ -1252,8 +1252,8 @@
     # Contains data about the attached devices for gyp_managed_install.
     'build_device_config_path': '<(PRODUCT_DIR)/build_devices.cfg',
 
-    'sas_dll_exists': '<!(python <(DEPTH)/build/dir_exists.py "<(sas_dll_path)")',
-    'wix_exists': '<!(python <(DEPTH)/build/dir_exists.py "<(wix_path)")',
+    'sas_dll_exists': '<!(python2.7 <(DEPTH)/build/dir_exists.py "<(sas_dll_path)")',
+    'wix_exists': '<!(python2.7 <(DEPTH)/build/dir_exists.py "<(wix_path)")',
 
     'windows_sdk_default_path': '<(DEPTH)/third_party/platformsdk_win8/files',
     'directx_sdk_default_path': '<(DEPTH)/third_party/directxsdk/files',
@@ -1303,18 +1303,18 @@
             # We directly set the gcc_version since we know what we use.
             'gcc_version%': 46,
           }, {
-            'gcc_version%': '<!(python <(DEPTH)/build/compiler_version.py)',
+            'gcc_version%': '<!(python2.7 <(DEPTH)/build/compiler_version.py)',
           }],
         ],
       }, {
         'gcc_version%': 0,
       }],
-      ['OS=="win" and "<!(python <(DEPTH)/build/dir_exists.py <(windows_sdk_default_path))"=="True"', {
+      ['OS=="win" and "<!(python2.7 <(DEPTH)/build/dir_exists.py <(windows_sdk_default_path))"=="True"', {
         'windows_sdk_path%': '<(windows_sdk_default_path)',
       }, {
         'windows_sdk_path%': 'C:/Program Files (x86)/Windows Kits/8.0',
       }],
-      ['OS=="win" and "<!(python <(DEPTH)/build/dir_exists.py <(directx_sdk_default_path))"=="True"', {
+      ['OS=="win" and "<!(python2.7 <(DEPTH)/build/dir_exists.py <(directx_sdk_default_path))"=="True"', {
         'directx_sdk_path%': '<(directx_sdk_default_path)',
       }, {
         'directx_sdk_path%': '$(DXSDK_DIR)',
@@ -1365,7 +1365,7 @@
         # The Mac SDK is set for iOS builds and passed through to Mac
         # sub-builds. This allows the Mac sub-build SDK in an iOS build to be
         # overridden from the command line the same way it is for a Mac build.
-        'mac_sdk%': '<!(python <(DEPTH)/build/mac/find_sdk.py 10.6)',
+        'mac_sdk%': '<!(python2.7 <(DEPTH)/build/mac/find_sdk.py 10.6)',
 
         # iOS SDK and deployment target support.  The |ios_sdk| value is left
         # blank so that when it is set in the project files it will be the
@@ -1585,7 +1585,7 @@
           }],
 
           ['branding=="Chrome" and buildtype=="Official"', {
-            'mac_sdk%': '<!(python <(DEPTH)/build/mac/find_sdk.py --verify <(mac_sdk_min) --sdk_path=<(mac_sdk_path))',
+            'mac_sdk%': '<!(python2.7 <(DEPTH)/build/mac/find_sdk.py --verify <(mac_sdk_min) --sdk_path=<(mac_sdk_path))',
             # Enable uploading crash dumps.
             'mac_breakpad_uploads%': 1,
             # Enable dumping symbols at build time for use by Mac Breakpad.
@@ -1593,7 +1593,7 @@
             # Enable Keystone auto-update support.
             'mac_keystone%': 1,
           }, { # else: branding!="Chrome" or buildtype!="Official"
-            'mac_sdk%': '<!(python <(DEPTH)/build/mac/find_sdk.py <(mac_sdk_min))',
+            'mac_sdk%': '<!(python2.7 <(DEPTH)/build/mac/find_sdk.py <(mac_sdk_min))',
             'mac_breakpad_uploads%': 0,
             'mac_breakpad%': 0,
             'mac_keystone%': 0,
