--- setup.py.orig	2022-08-06 09:43:13 UTC
+++ setup.py
@@ -13,12 +13,12 @@ package_data = \
                     'resources/templates/*']}
 
 install_requires = \
-['cepa==1.8.3',
+['cepa',
  'click',
  'colorama',
  'eventlet',
- 'flask-socketio==5.0.1',
- 'flask==1.1.4',
+ 'flask-socketio',
+ 'flask',
  'gevent-websocket',
  'psutil',
  'pynacl',
