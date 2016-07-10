--- pavement.py.orig	2015-09-03 06:12:10 UTC
+++ pavement.py
@@ -25,9 +25,9 @@ options = environment.options
 # guessit 0.10.4 stops supporting python 2.6, the tests also start failing on 2.7
 # Path keeps messing about with case, so anything under 6.2 will be broken now
 install_requires = ['FeedParser>=5.1.3', 'SQLAlchemy >=0.7.5, !=0.9.0, <1.999', 'PyYAML',
-                    'beautifulsoup4>=4.1, !=4.2.0, <4.4', 'html5lib>=0.11', 'PyRSS2Gen', 'pynzb', 'progressbar', 'rpyc',
+                    'beautifulsoup4>=4.1', 'html5lib>=0.11', 'PyRSS2Gen', 'pynzb', 'progressbar', 'rpyc',
                     'jinja2', 'requests>=1.0, !=2.4.0, <2.99', 'python-dateutil!=2.0, !=2.2', 'jsonschema>=2.0',
-                    'python-tvrage', 'tmdb3', 'path.py>=6.2', 'guessit>=0.9.3, <0.10.4', 'apscheduler']
+                    'python-tvrage', 'tmdb3', 'path.py>=6.2', 'guessit>=0.9.3', 'apscheduler']
 if sys.version_info < (2, 7):
     # argparse is part of the standard library in python 2.7+
     install_requires.append('argparse')
