--- setup.py.orig	2013-01-17 21:00:33.000000000 +0100
+++ setup.py	2013-04-27 23:26:09.000000000 +0200
@@ -24,7 +24,7 @@
 def read(fname):
     return open(os.path.join(os.path.dirname(__file__), fname)).read()
 
-required = ['beautifulsoup4 >= 4.0', 'guessit >= 0.4.1', 'requests < 1.0', 'enzyme >= 0.1', 'html5lib']
+required = ['beautifulsoup4 >= 4.0', 'guessit >= 0.4.1', 'requests >= 1.1', 'enzyme >= 0.1', 'html5lib']
 if sys.hexversion < 0x20700f0:
     required.append('argparse >= 1.1')
 
