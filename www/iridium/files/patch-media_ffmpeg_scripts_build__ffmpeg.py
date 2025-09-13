--- media/ffmpeg/scripts/build_ffmpeg.py.orig	2025-09-11 13:19:19 UTC
+++ media/ffmpeg/scripts/build_ffmpeg.py
@@ -33,7 +33,7 @@ NDK_ROOT_DIR = os.path.abspath(
 SUCCESS_TOKEN = 'THIS_BUILD_WORKED'
 
 sys.path.append(os.path.join(CHROMIUM_ROOT_DIR, 'build'))
-import gn_helpers
+#import gn_helpers
 
 BRANDINGS = [
     'Chrome',
@@ -43,6 +43,8 @@ BRANDINGS = [
 ARCH_MAP = {
     'android': ['ia32', 'x64', 'arm-neon', 'arm64'],
     'linux': ['ia32', 'x64', 'noasm-x64', 'arm', 'arm-neon', 'arm64', 'riscv64'],
+    'openbsd': ['x64', 'arm64', 'ia32'],
+    'freebsd': ['x64', 'arm64', 'ia32'],
     'mac': ['x64', 'arm64'],
     'win': ['ia32', 'x64', 'arm64'],
 }
@@ -124,7 +126,7 @@ def PrintAndCheckCall(argv, *args, **kwargs):
 
 
 def GetDsoName(target_os, dso_name, dso_version):
-    if target_os in ('linux', 'linux-noasm', 'android'):
+    if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd'):
         return 'lib%s.so.%s' % (dso_name, dso_version)
     elif target_os == 'mac':
         return 'lib%s.%s.dylib' % (dso_name, dso_version)
@@ -475,7 +477,7 @@ def BuildFFmpeg(target_os, target_arch, host_os, host_
     # removing <sys/sysctl.h> soon, so this is needed to silence a deprecation
     # #warning which will be converted to an error via -Werror.
     # There is also no prctl.h
-    if target_os in ['linux', 'linux-noasm']:
+    if target_os in ['linux', 'linux-noasm', 'openbsd', 'freebsd']:
         pre_make_rewrites += [
             (r'(#define HAVE_SYSCTL [01])',
              r'#define HAVE_SYSCTL 0 /* \1 -- forced to 0 for Fuchsia */'),
@@ -598,7 +600,7 @@ def main(argv):
     configure_args = args[2:]
 
     if target_os not in ('android', 'linux', 'linux-noasm', 'mac', 'win',
-                         'all'):
+                         'all', 'openbsd', 'freebsd'):
         parser.print_help()
         return 1
 
@@ -712,7 +714,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
             '--optflags="-O2"',
         ])
 
-    if target_os in ('linux', 'linux-noasm', 'android'):
+    if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd'):
         if target_arch == 'x64':
             if target_os == 'android':
                 configure_flags['Common'].extend([
@@ -827,9 +829,6 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
 
                 configure_flags['Common'].extend([
                     '--target-os=linux',
-                    '--sysroot=' +
-                    os.path.join(CHROMIUM_ROOT_DIR,
-                                 'build/linux/debian_bullseye_arm64-sysroot'),
                     # See crbug.com/1467681. These could be removed eventually
                     '--disable-dotprod',
                     '--disable-i8mm',
