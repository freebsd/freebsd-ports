- same patch as suggested here: https://github.com/oddt/oddt/issues/160

--- setup.py.orig	2022-03-25 17:16:33 UTC
+++ setup.py
@@ -9,7 +9,7 @@ setup(name='oddt',
       author_email='mwojcikowski@ibb.waw.pl',
       url='https://github.com/oddt/oddt',
       license='BSD',
-      packages=find_packages(),
+      packages=find_packages(exclude=['test*']),
       package_data={'oddt.scoring.functions': ['NNScore/*.csv',
                                                'RFScore/*.csv',
                                                'PLECscore/*.json',
