--- setup.py.orig	2017-05-19 19:22:47 UTC
+++ setup.py
@@ -12,5 +12,5 @@ setup(name='crmsh',
       packages=['crmsh'],
       install_requires=['parallax', 'lxml', 'PyYAML', 'python-dateutil'],
       scripts=['bin/crm'],
-      data_files=[('/usr/share/crmsh', ['doc/crm.8.adoc'])],
+      data_files=[('%%DATADIR%%', ['doc/crm.8.adoc'])],
       include_package_data=True)
