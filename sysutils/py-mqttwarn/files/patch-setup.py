# Fix the versions according to what has been tested to work
# change == to >=
--- setup.py.orig	2020-08-11 14:49:15 UTC
+++ setup.py
@@ -7,112 +7,112 @@ here = os.path.abspath(os.path.dirname(__file__))
 README = open(os.path.join(here, 'README.rst')).read()
 
 requires = [
-    'six==1.13.0',
-    'paho-mqtt==1.5.0',
-    'jinja2==2.10.3',
-    'attrs==19.3.0',
-    'docopt==0.6.2',
-    'requests==2.22.0',
-    'future==0.18.2',
-    'configparser==4.0.2',
+    'six>=1.13.0',
+    'paho-mqtt>=1.4.0',
+    'jinja2>=2.10.1',
+    'attrs>=19.3.0',
+    'docopt>=0.6.2',
+    'requests>=2.22.0',
+    'future>=0.18.2',
+    'configparser>=3.5.3',
 ]
 
 extras = {
     'amqp': [
-        'puka==0.0.7',
+        'puka>=0.0.7',
     ],
     'apns': [
-        'apns==2.0.1',
+        'apns>=2.0.1',
     ],
     'apprise': [
-        'apprise==0.8.5',
+        'apprise>=0.8.5',
     ],
     'asterisk': [
-        'pyst2==0.5.0',
+        'pyst2>=0.5.0',
     ],
     'celery': [
         'celery',
     ],
     'dnsupdate': [
-        'dnspython==1.15.0',
+        'dnspython>=1.15.0',
     ],
     'fbchat': [
-        'fbchat==1.3.6',
+        'fbchat>=1.3.6',
     ],
     'gss': [
-        'gdata==2.0.18',
+        'gdata>=2.0.18',
     ],
     'gss2': [
-        'gspread==2.1.1',
-        'oauth2client==4.1.2',
-        #'google-api-python-client==1.7.11',
+        'gspread>=2.1.1',
+        'oauth2client>=4.1.2',
+        #'google-api-python-client>=1.7.11',
     ],
     'iothub': [
-        'iothub-client==1.1.2.0',
+        'iothub-client>=1.1.2.0',
     ],
     'mysql': [
         'mysql',
     ],
     'nma': [
-        'PyNMA==1.0',
+        'PyNMA>=1.0',
     ],
     'nsca': [
-        'pynsca==1.6',
+        'pynsca>=1.6',
     ],
     'osxnotify': [
-        'pync==1.6.1',
+        'pync>=1.6.1',
     ],
     'pastebinpub': [
-        'Pastebin==1.1.2',
+        'Pastebin>=1.1.2',
     ],
     'postgres': [
-        'psycopg2==2.7.4',
+        'psycopg2>=2.7.4',
     ],
     'prowl': [
         'prowlpy>=0.52',
     ],
     'pushbullet': [
-        'PushbulletPythonLibrary==2.3',
+        'PushbulletPythonLibrary>=2.3',
     ],
     'redispub': [
-        'redis==2.10.6',
+        'redis>=2.10.6',
     ],
     'rrdtool': [
-        'rrdtool==0.1.12',
+        'rrdtool>=0.1.12',
     ],
     'serial': [
-        'pyserial==3.4',
+        'pyserial>=3.4',
     ],
     'slack': [
-        'slacker==0.9.65',
+        'slacker>=0.9.65',
     ],
     'ssh': [
-        'paramiko==2.4.1',
+        'paramiko>=2.4.1',
     ],
     'tootpaste': [
-        'Mastodon.py==1.2.2',
+        'Mastodon.py>=1.2.2',
     ],
     'twilio': [
-        'twilio==6.11.0',
+        'twilio>=6.11.0',
     ],
     'twitter': [
-        'python-twitter==3.4.1',
+        'python-twitter>=3.4.1',
     ],
     'websocket': [
-        'websocket-client==0.47.0',
+        'websocket-client>=0.47.0',
     ],
     'xively': [
         'xively-python',
     ],
     'xmpp': [
-        'xmpppy==0.6.1',
-        'dnspython==1.16.0',
+        'xmpppy>=0.6.1',
+        'dnspython>=1.16.0',
     ],
     'test': [
-        'pytest==4.6.7',
-        'pytest-cov==2.8.1',
+        'pytest>=4.6.7',
+        'pytest-cov>=2.8.1',
         'lovely.testlayers>=0.7.1',
-        'tox==3.14.2',
+        'tox>=3.14.2',
     ],
 }
 
