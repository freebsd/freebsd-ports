# Unpin mock dependency. mock 3.x works
# https://github.com/praw-dev/prawcore/pull/77

--- setup.py.orig	2019-05-17 03:34:46 UTC
+++ setup.py
@@ -40,7 +40,7 @@ setup(name=PACKAGE_NAME,
       tests_require=['betamax >=0.8, <0.9',
                      'betamax_matchers >=0.4.0, <0.5',
                      'betamax-serializers >=0.2.0, <0.3',
-                     'mock >=0.8, <3',
+                     'mock >=0.8',
                      'testfixtures >4.13.2, <7'],
       test_suite='tests',
       url='https://github.com/praw-dev/prawcore',
