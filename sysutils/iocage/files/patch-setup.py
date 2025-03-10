--- setup.py.orig	2024-09-20 06:45:27 UTC
+++ setup.py
@@ -30,10 +30,10 @@ from setuptools import find_packages, setup
 
 if os.path.isdir("/".join([sys.prefix, "etc/init.d"])):
     _data = [('etc/init.d', ['rc.d/iocage']),
-             ('man/man8', ['iocage.8.gz'])]
+             ('share/man/man8', ['iocage.8.gz'])]
 else:
     _data = [('etc/rc.d', ['rc.d/iocage']),
-             ('man/man8', ['iocage.8.gz'])]
+             ('share/man/man8', ['iocage.8.gz'])]
 
 if os.path.isdir("/".join([sys.prefix, "share/zsh/site-functions/"])):
     _data.append(('share/zsh/site-functions', ['zsh-completion/_iocage']))
