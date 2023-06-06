--- third_party/ffmpeg/chromium/scripts/build_ffmpeg.py.orig	2023-06-05 19:39:05 UTC
+++ third_party/ffmpeg/chromium/scripts/build_ffmpeg.py
@@ -29,7 +29,7 @@ NDK_ROOT_DIR = os.path.abspath(
 SUCCESS_TOKEN = 'THIS_BUILD_WORKED'
 
 sys.path.append(os.path.join(CHROMIUM_ROOT_DIR, 'build'))
-import gn_helpers
+#import gn_helpers
 
 BRANDINGS = [
     'Chrome',
@@ -42,6 +42,8 @@ ARCH_MAP = {
     'linux': [
         'ia32', 'x64', 'noasm-x64', 'arm', 'arm-neon', 'arm64'
     ],
+    'openbsd': ['x64', 'arm64', 'ia32'],
+    'freebsd': ['x64', 'arm64', 'ia32'],
     'mac': ['x64', 'arm64'],
     'win': ['ia32', 'x64', 'arm64'],
 }
@@ -51,6 +53,8 @@ USAGE_END = """
 Valid combinations are android     [%(android)s]
                        linux       [%(linux)s]
                        mac         [%(mac)s]
+                       openbsd     [%(openbsd)s]
+                       freebsd     [%(freebsd)s]
                        win         [%(win)s]
 
 If no target architecture is specified all will be built.
@@ -123,6 +127,10 @@ def PrintAndCheckCall(argv, *args, **kwargs):
 def DetermineHostOsAndArch():
   if platform.system() == 'Linux':
     host_os = 'linux'
+  if platform.system() == 'OpenBSD':
+    host_os = 'openbsd'
+  elif platform.system() == 'FreeBSD':
+    host_os = 'freebsd'
   elif platform.system() == 'Darwin':
     host_os = 'mac'
   elif platform.system() == 'Windows' or 'CYGWIN_NT' in platform.system():
@@ -132,7 +140,7 @@ def DetermineHostOsAndArch():
 
   if re.match(r'i.86', platform.machine()):
     host_arch = 'ia32'
-  elif platform.machine() == 'x86_64' or platform.machine() == 'AMD64':
+  elif platform.machine() == 'x86_64' or platform.machine() == 'AMD64' or platform.machine() == 'amd64':
     host_arch = 'x64'
   elif platform.machine() == 'aarch64':
     host_arch = 'arm64'
@@ -149,7 +157,7 @@ def DetermineHostOsAndArch():
 
 
 def GetDsoName(target_os, dso_name, dso_version):
-  if target_os in ('linux', 'linux-noasm', 'android'):
+  if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd'):
     return 'lib%s.so.%s' % (dso_name, dso_version)
   elif target_os == 'mac':
     return 'lib%s.%s.dylib' % (dso_name, dso_version)
@@ -492,7 +500,7 @@ def BuildFFmpeg(target_os, target_arch, host_os, host_
   # removing <sys/sysctl.h> soon, so this is needed to silence a deprecation
   # #warning which will be converted to an error via -Werror.
   # There is also no prctl.h
-  if target_os in ['linux', 'linux-noasm']:
+  if target_os in ['linux', 'linux-noasm', 'openbsd', 'freebsd']:
     pre_make_rewrites += [
         (r'(#define HAVE_SYSCTL [01])',
          r'#define HAVE_SYSCTL 0 /* \1 -- forced to 0 for Fuchsia */'),
@@ -613,7 +621,7 @@ def main(argv):
   configure_args = args[2:]
 
 
-  if target_os not in ('android', 'linux', 'linux-noasm', 'mac', 'win', 'all'):
+  if target_os not in ('android', 'linux', 'linux-noasm', 'mac', 'win', 'all', 'openbsd', 'freebsd'):
     parser.print_help()
     return 1
 
@@ -735,7 +743,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
         '--enable-parser=vp3,vp8',
     ])
 
-  if target_os in ('linux', 'linux-noasm', 'android'):
+  if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd'):
     if target_arch == 'x64':
       if target_os == 'android':
         configure_flags['Common'].extend([
@@ -745,7 +753,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
         configure_flags['Common'].extend([
           '--enable-lto',
           '--arch=x86_64',
-          '--target-os=linux',
+          '--target-os=' + target_os,
         ])
 
         if host_arch != 'x64':
@@ -836,7 +844,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
               '--extra-cflags=-mfpu=vfpv3-d16',
           ])
     elif target_arch == 'arm64':
-      if target_os != 'android':
+      if target_os != 'android' and target_os != 'openbsd' and target_os != 'freebsd':
         if host_arch != 'arm64':
           configure_flags['Common'].extend([
             '--enable-cross-compile',
@@ -898,7 +906,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
             '--disable-mips64r2',
             '--enable-msa',
         ])
-      if target_os == 'linux':
+      if target_os == 'Linux':
         configure_flags['Common'].extend([
             '--enable-cross-compile',
             '--target-os=linux',
@@ -1049,7 +1057,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
         'Chrome', configure_flags['Common'] + configure_flags['ChromeAndroid'] +
         configure_args)
 
-  if target_os in ['linux', 'linux-noasm']:
+  if target_os in ['linux', 'linux-noasm', 'openbsd', 'freebsd']:
     # ChromeOS enables MPEG4 which requires error resilience :(
     chrome_os_flags = (
         configure_flags['Common'] + configure_flags['Chrome'] +
