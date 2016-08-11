--- setup.py.orig	2016-06-29 09:52:25 UTC
+++ setup.py
@@ -21,9 +21,5 @@ setup(name = PACKAGE_NAME,
       platforms = ["Unix","Windows"],
       packages = ['impacket', 'impacket.dcerpc', 'impacket.examples', 'impacket.dcerpc.v5', 'impacket.dcerpc.v5.dcom', 'impacket.krb5', 'impacket.ldap', 'impacket.examples.ntlmrelayx', 'impacket.examples.ntlmrelayx.clients', 'impacket.examples.ntlmrelayx.servers', 'impacket.examples.ntlmrelayx.utils'],
       scripts = glob.glob(os.path.join('examples', '*.py')),
-      data_files = [(os.path.join('share', 'doc', PACKAGE_NAME), ['README.md', 'LICENSE']+glob.glob('doc/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'dot11'),glob.glob('impacket/testcases/dot11/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'ImpactPacket'),glob.glob('impacket/testcases/ImpactPacket/*')),
-                    (os.path.join('share', 'doc', PACKAGE_NAME, 'testcases', 'SMB_RPC'),glob.glob('impacket/testcases/SMB_RPC/*'))],
       requires=['pycrypto (>=2.6)', 'pyasn1 (>=0.1.7)'],
       )
