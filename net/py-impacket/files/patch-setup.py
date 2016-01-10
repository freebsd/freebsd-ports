--- setup.py.orig	2015-05-05 09:53:44 UTC
+++ setup.py
@@ -21,9 +21,5 @@ setup(name = PACKAGE_NAME,
       platforms = ["Unix","Windows"],
       packages = ['impacket', 'impacket.dcerpc', 'impacket.examples', 'impacket.dcerpc.v5', 'impacket.dcerpc.v5.dcom', 'impacket.krb5'],
       scripts = glob.glob(os.path.join('examples', '*.py')),
-      data_files = [(os.path.join('share', 'doc', PACKAGE_NAME), ['README.md', 'LICENSE']+glob.glob('doc/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'dot11'),glob.glob('impacket/testcases/dot11/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'ImpactPacket'),glob.glob('impacket/testcases/ImpactPacket/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'SMB_RPC'),glob.glob('impacket/testcases/SMB_RPC/*'))],
       requires=['pycrypto (>=2.6)', 'pyasn1 (>=0.1.7)'],
       )
