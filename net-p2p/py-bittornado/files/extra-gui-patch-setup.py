
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
+	['alloc.gif','black1.ico','black.ico','blue.ico','green1.ico','green.ico',
+          'icon_bt.ico','icon_done.ico','red.ico','white.ico',
+         'yellow1.ico','yellow.ico'])]
     )
