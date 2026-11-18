--- components/safe_browsing/content/resources/gen_file_type_proto.py.orig	2026-11-17 21:17:00 UTC
+++ components/safe_browsing/content/resources/gen_file_type_proto.py
@@ -38,6 +38,8 @@ def PlatformTypes():
         "android": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_ANDROID,
         "chromeos": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_CHROME_OS,
         "linux": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "openbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "freebsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
         "mac": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_MAC,
         "win": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_WINDOWS,
         # LINT.ThenChange(BUILD.gn:PlatformTypes)
@@ -192,7 +194,7 @@ class DownloadFileTypeProtoGenerator(BinaryProtoGenera
             '-t',
             '--type',
             help='The platform type. One of android, chromeos, '
-            + 'linux, mac, win',
+            + 'linux, mac, win, openbsd, freebsd',
         )
 
     def AddExtraCommandLineArgsForVirtualEnvRun(self, opts, command):
