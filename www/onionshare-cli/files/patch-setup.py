--- setup.py.orig	2022-12-27 15:18:17 UTC
+++ setup.py
@@ -13,21 +13,21 @@ package_data = \
                     'resources/templates/*']}
 
 install_requires = \
-['click',
+['cepa', 'click',
  'colorama',
  'eventlet',
- 'flask-socketio==5.3.1',
- 'flask==2.0.3',
+ 'flask-socketio',
+ 'flask',
  'gevent-websocket',
  'psutil',
  'pynacl',
  'pysocks',
  'requests[socks]',
  'setuptools',
- 'stem==1.8.1',
+ 'stem',
  'unidecode',
  'urllib3',
- 'werkzeug>=2.0.3,<2.1.0']
+ 'werkzeug>=2.0.3,<2.2.0']
 
 entry_points = \
 {'console_scripts': ['onionshare-cli = onionshare_cli:main']}
