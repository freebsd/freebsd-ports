--- components/safe_browsing/content/resources/gen_file_type_proto.py.orig	2022-02-07 13:39:41 UTC
+++ components/safe_browsing/content/resources/gen_file_type_proto.py
@@ -35,6 +35,7 @@ def PlatformTypes():
         download_file_types_pb2.DownloadFileType.PLATFORM_CHROME_OS,
         "fuchsia": download_file_types_pb2.DownloadFileType.PLATFORM_FUCHSIA,
         "linux": download_file_types_pb2.DownloadFileType.PLATFORM_LINUX,
+        "openbsd": download_file_types_pb2.DownloadFileType.PLATFORM_LINUX,
         "mac": download_file_types_pb2.DownloadFileType.PLATFORM_MAC,
         "win": download_file_types_pb2.DownloadFileType.PLATFORM_WINDOWS,
     }
@@ -179,7 +180,7 @@ class DownloadFileTypeProtoGenerator(BinaryProtoGenera
             '-t',
             '--type',
             help='The platform type. One of android, chromeos, ' +
-            'linux, mac, win')
+            'linux, mac, win, openbsd')
 
     def AddExtraCommandLineArgsForVirtualEnvRun(self, opts, command):
         if opts.type is not None:
