
$FreeBSD$

--- setup.py.orig	Sun May 16 13:40:26 2004
+++ setup.py	Tue May 25 10:14:43 2004
@@ -25,5 +25,9 @@
         "bttest.py",
         'btmaketorrentgui.py', 'btcopyannounce.py', 'btsethttpseeds.py',
         'bt-t-make.py',
-        ]
+        ],
+    data_files = [('share/BitTornado', 
+	['icons/alloc.gif','icons/black1.ico','icons/black.ico','icons/blue.ico','icons/green1.ico','icons/green.ico',
+          'icons/icon_bt.ico','icons/icon_done.ico','icons/red.ico','icons/white.ico',
+         'icons/yellow1.ico','icons/yellow.ico'])]
     )
