--- setup.py.orig	2021-11-30 08:16:52 UTC
+++ setup.py
@@ -34,7 +34,7 @@ setup(name='slackeventsapi',
       long_description_content_type='text/x-rst',
       long_description=long_description,
       install_requires=[
-          'flask>=2,<3',
+          'flask>=2',
           'pyee>=8',
       ],
       classifiers=[
