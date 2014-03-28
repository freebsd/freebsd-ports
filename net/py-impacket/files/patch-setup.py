--- ./setup.py.orig	2014-01-30 16:07:52.000000000 +0000
+++ ./setup.py	2014-03-26 22:12:00.000000000 +0000
@@ -21,8 +21,4 @@
       platforms = ["Unix","Windows"],
       packages = ['impacket', 'impacket.dcerpc', 'impacket.examples', 'impacket.dcerpc.v5'],
       scripts = glob.glob(os.path.join('examples', '*.py')),
-      data_files = [(os.path.join('share', 'doc', PACKAGE_NAME), ['README', 'LICENSE']+glob.glob('doc/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'dot11'),glob.glob('impacket/testcases/dot11/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'ImpactPacket'),glob.glob('impacket/testcases/ImpactPacket/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'SMB-RPC'),glob.glob('impacket/testcases/SMB-RPC/*'))],
       )
