--- chrome/browser/resources/safe_browsing/gen_file_type_proto.py.orig	2016-08-04 11:13:17.290964000 -0400
+++ chrome/browser/resources/safe_browsing/gen_file_type_proto.py	2016-08-04 11:13:54.901432000 -0400
@@ -39,6 +39,7 @@
     "android": config_pb2.DownloadFileType.PLATFORM_ANDROID,
     "chromeos": config_pb2.DownloadFileType.PLATFORM_CHROME_OS,
     "linux": config_pb2.DownloadFileType.PLATFORM_LINUX,
+    "freebsd": config_pb2.DownloadFileType.PLATFORM_LINUX,
     "mac": config_pb2.DownloadFileType.PLATFORM_MAC,
     "win": config_pb2.DownloadFileType.PLATFORM_WINDOWS,
   }
@@ -157,7 +158,7 @@
                      'fix for http://crbug.com/605592')
   parser.add_option('-t', '--type',
                     help='The platform type. One of android, chromeos, ' +
-                    'linux, mac, win')
+                    'linux, freebsd, mac, win')
   parser.add_option('-i', '--infile',
                     help='The ASCII DownloadFileType-proto file to read.')
   parser.add_option('-o', '--outfile',
