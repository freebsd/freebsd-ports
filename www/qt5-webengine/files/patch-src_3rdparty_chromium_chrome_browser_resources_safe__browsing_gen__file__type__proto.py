--- src/3rdparty/chromium/chrome/browser/resources/safe_browsing/gen_file_type_proto.py.orig	2017-01-26 00:49:09 UTC
+++ src/3rdparty/chromium/chrome/browser/resources/safe_browsing/gen_file_type_proto.py
@@ -50,6 +50,7 @@ def PlatformTypes():
     "android": config_pb2.DownloadFileType.PLATFORM_ANDROID,
     "chromeos": config_pb2.DownloadFileType.PLATFORM_CHROME_OS,
     "linux": config_pb2.DownloadFileType.PLATFORM_LINUX,
+    "bsd": config_pb2.DownloadFileType.PLATFORM_LINUX,
     "mac": config_pb2.DownloadFileType.PLATFORM_MAC,
     "win": config_pb2.DownloadFileType.PLATFORM_WINDOWS,
   }
@@ -201,7 +202,7 @@ def main():
                     'Outfile must have a %d for version and %s for platform.')
   parser.add_option('-t', '--type',
                     help='The platform type. One of android, chromeos, ' +
-                    'linux, mac, win')
+                    'linux, bsd, mac, win')
   parser.add_option('-i', '--infile',
                     help='The ASCII DownloadFileType-proto file to read.')
   parser.add_option('-d', '--outdir',
