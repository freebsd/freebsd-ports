--- third_party/ffmpeg/chromium/scripts/build_ffmpeg.py.orig	2024-03-22 08:19:40 UTC
+++ third_party/ffmpeg/chromium/scripts/build_ffmpeg.py
@@ -32,7 +32,7 @@ NDK_ROOT_DIR = os.path.abspath(
 SUCCESS_TOKEN = 'THIS_BUILD_WORKED'
 
 sys.path.append(os.path.join(CHROMIUM_ROOT_DIR, 'build'))
-import gn_helpers
+#import gn_helpers
 
 BRANDINGS = [
     'Chrome',
@@ -45,6 +45,8 @@ ARCH_MAP = {
     'linux': [
         'ia32', 'x64', 'noasm-x64', 'arm', 'arm-neon', 'arm64'
     ],
+    'openbsd': ['x64', 'arm64', 'ia32'],
+    'freebsd': ['x64', 'arm64', 'ia32'],
     'mac': ['x64', 'arm64'],
     'win': ['ia32', 'x64', 'arm64'],
 }
@@ -54,6 +56,8 @@ USAGE_END = """
 Valid combinations are android     [%(android)s]
                        linux       [%(linux)s]
                        mac         [%(mac)s]
+                       openbsd     [%(openbsd)s]
+                       freebsd     [%(freebsd)s]
                        win         [%(win)s]
 
 If no target architecture is specified all will be built.
@@ -124,7 +128,7 @@ def PrintAndCheckCall(argv, *args, **kwargs):
 
 
 def GetDsoName(target_os, dso_name, dso_version):
-  if target_os in ('linux', 'linux-noasm', 'android'):
+  if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd'):
     return 'lib%s.so.%s' % (dso_name, dso_version)
   elif target_os == 'mac':
     return 'lib%s.%s.dylib' % (dso_name, dso_version)
@@ -467,7 +471,7 @@ def BuildFFmpeg(target_os, target_arch, host_os, host_
   # removing <sys/sysctl.h> soon, so this is needed to silence a deprecation
   # #warning which will be converted to an error via -Werror.
   # There is also no prctl.h
-  if target_os in ['linux', 'linux-noasm']:
+  if target_os in ['linux', 'linux-noasm', 'openbsd', 'freebsd']:
     pre_make_rewrites += [
         (r'(#define HAVE_SYSCTL [01])',
          r'#define HAVE_SYSCTL 0 /* \1 -- forced to 0 for Fuchsia */'),
@@ -594,7 +598,7 @@ def main(argv):
   configure_args = args[2:]
 
 
-  if target_os not in ('android', 'linux', 'linux-noasm', 'mac', 'win', 'all'):
+  if target_os not in ('android', 'linux', 'linux-noasm', 'mac', 'win', 'all', 'openbsd', 'freebsd'):
     parser.print_help()
     return 1
 
@@ -710,7 +714,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
         '--enable-parser=vp3,vp8',
     ])
 
-  if target_os in ('linux', 'linux-noasm', 'android'):
+  if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd'):
     if target_arch == 'x64':
       if target_os == 'android':
         configure_flags['Common'].extend([
@@ -822,8 +826,6 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
 
         configure_flags['Common'].extend([
             '--target-os=linux',
-            '--sysroot=' + os.path.join(CHROMIUM_ROOT_DIR,
-                                        'build/linux/debian_bullseye_arm64-sysroot'),
             # See crbug.com/1467681. These could be removed eventually
             '--disable-dotprod',
             '--disable-i8mm',
@@ -1027,7 +1029,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
         'Chrome', configure_flags['Common'] + configure_flags['ChromeAndroid'] +
         configure_args)
 
-  if target_os in ['linux', 'linux-noasm']:
+  if target_os in ['linux', 'linux-noasm', 'openbsd', 'freebsd']:
     # ChromeOS enables MPEG4 which requires error resilience :(
     chrome_os_flags = (
         configure_flags['Common'] + configure_flags['Chrome'] +
