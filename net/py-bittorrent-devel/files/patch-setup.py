--- setup.py.orig	Fri Dec 24 06:59:35 2004
+++ setup.py	Fri Dec 24 06:59:44 2004
@@ -29,8 +29,6 @@
 
 data_files = [ (img_root        , glob.glob('images/*png')+['images/bittorrent.ico',]),
                (img_root+'/logo', glob.glob('images/logo/bittorrent_[0-9]*.png')     ),
-               (doc_root        , ['credits.txt', 'LICENSE.txt',
-                                   'README.txt', 'redirdonate.html']       ),
                ]
 
 setup(
