diff -ruN BitTorrent-3.4.2/btcompletedir.py BitTorrent.cvs/btcompletedir.py
--- btcompletedir.py	Wed Mar  3 14:44:06 2004
+++ btcompletedir.py	Sun May 23 04:31:44 2004
@@ -30,6 +30,8 @@
         subtotal[0] += x
         vc(float(subtotal[0]) / total)
     for i in togen:
+        if flag.isSet():
+            break
         t = split(i)
         if t[1] == '':
             i = t[0]
