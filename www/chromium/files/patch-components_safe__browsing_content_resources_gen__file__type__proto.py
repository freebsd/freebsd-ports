--- components/safe_browsing/content/resources/gen_file_type_proto.py.orig	2026-11-19 12:25:27 UTC
+++ components/safe_browsing/content/resources/gen_file_type_proto.py
@@ -38,6 +38,8 @@ def PlatformTypes():
         "android": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_ANDROID,  # noqa: F821
         "chromeos": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_CHROME_OS,  # noqa: F821
         "linux": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,  # noqa: F821
+        "openbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,  # noqa: F821
+        "freebsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,  # noqa: F821
         "mac": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_MAC,  # noqa: F821
         "win": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_WINDOWS,  # noqa: F821
         # LINT.ThenChange(BUILD.gn:PlatformTypes)
@@ -192,7 +194,7 @@ class DownloadFileTypeProtoGenerator(BinaryProtoGenera
             '-t',
             '--type',
             help='The platform type. One of android, chromeos, '
-            + 'linux, mac, win',
+            + 'linux, mac, win, openbsd, freebsd',
         )
 
     def AddExtraCommandLineArgsForVirtualEnvRun(self, opts, command):
