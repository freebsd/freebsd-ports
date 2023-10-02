--- setup.py.orig	2023-09-21 00:08:28.427651000 -0500
+++ setup.py	2023-09-21 00:09:29.055566000 -0500
@@ -39,12 +39,6 @@
 except Exception:
     VER_LOCAL = ""
 
-if platform.system() != 'Darwin':
-    data_files = [(os.path.join('share', 'doc', PACKAGE_NAME), ['README.md', 'LICENSE']+glob.glob('doc/*'))]
-else:
-    data_files = []
-
-
 def read(fname):
     return open(os.path.join(os.path.dirname(__file__), fname)).read()
 
@@ -66,7 +60,6 @@
               'impacket.examples.ntlmrelayx.servers.socksplugins', 'impacket.examples.ntlmrelayx.utils',
               'impacket.examples.ntlmrelayx.attacks', 'impacket.examples.ntlmrelayx.attacks.httpattacks'],
     scripts=glob.glob(os.path.join('examples', '*.py')),
-    data_files=data_files,
     install_requires=['pyasn1>=0.2.3', 'pycryptodomex', 'pyOpenSSL>=21.0.0', 'six', 'ldap3>=2.5,!=2.5.2,!=2.5.0,!=2.6',
                       'ldapdomaindump>=0.9.0', 'flask>=1.0', 'future', 'charset_normalizer', 'dsinternals'],
     extras_require={'pyreadline:sys_platform=="win32"': [],
