--- setup.py.orig	2018-08-31 08:58:06.065718000 -0300
+++ setup.py	2018-08-31 08:58:06.065524000 -0300
@@ -10,11 +10,6 @@
 
 PACKAGE_NAME = "impacket"
 
-if platform.system() != 'Darwin':
-    data_files = [(os.path.join('share', 'doc', PACKAGE_NAME), ['README.md', 'LICENSE']+glob.glob('doc/*'))]
-else:
-    data_files = []
-
 def read(fname):
     return open(os.path.join(os.path.dirname(__file__), fname)).read()
 
@@ -36,7 +31,6 @@
                 'impacket.examples.ntlmrelayx.servers.socksplugins', 'impacket.examples.ntlmrelayx.utils',
                 'impacket.examples.ntlmrelayx.attacks'],
       scripts = glob.glob(os.path.join('examples', '*.py')),
-      data_files = data_files,
       install_requires=['pyasn1>=0.2.3', 'pycrypto>=2.6.1', 'pyOpenSSL>=0.13.1', 'six', 'ldap3>=2.5.0', 'ldapdomaindump', 'flask'],
       extras_require={
                       'pyreadline:sys_platform=="win32"': [],
