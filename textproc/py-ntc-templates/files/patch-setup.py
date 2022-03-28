--- setup.py.orig	2022-03-27 21:10:43 UTC
+++ setup.py
@@ -0,0 +1,26 @@
+# -*- coding: utf-8 -*-
+from setuptools import setup
+
+packages = \
+['ntc_templates']
+
+package_data = \
+{'': ['*'], 'ntc_templates': ['templates/*']}
+
+install_requires = \
+['textfsm>=1.1.0,<2.0.0']
+
+setup_kwargs = {
+    'name': 'ntc-templates',
+    'version': '3.0.0',
+    'description': "TextFSM Templates for Network Devices, and Python wrapper for TextFSM's CliTable.",
+    'author': 'Network to Code',
+    'author_email': 'info@networktocode.com',
+    'url': 'https://github.com/networktocode/ntc-templates',
+    'packages': packages,
+    'package_data': package_data,
+    'install_requires': install_requires,
+    'python_requires': '>=3.6,<4.0',
+}
+
+setup(**setup_kwargs)
