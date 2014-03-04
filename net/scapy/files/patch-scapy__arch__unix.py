--- ./scapy/arch/unix.py.orig	2010-08-10 23:09:40.000000000 +0000
+++ ./scapy/arch/unix.py	2014-03-03 23:59:21.000000000 +0000
@@ -38,6 +38,8 @@
     ok = 0
     mtu_present = False
     prio_present = False
+    refs_present = False
+    use_present = False
     routes = []
     pending_if = []
     for l in f.readlines():
@@ -51,6 +53,8 @@
                 ok = 1
                 mtu_present = l.find("Mtu") >= 0
                 prio_present = l.find("Prio") >= 0
+                refs_present = l.find("Refs") >= 0
+                use_present = l.find("Use") >= 0
             continue
         if not l:
             break
@@ -64,7 +68,10 @@
         else:
             rt = l.split()
             dest,gw,flg = rt[:3]
-            netif = rt[5+mtu_present+prio_present]
+            if scapy.arch.FREEBSD:
+                netif = rt[3+refs_present+use_present+mtu_present]
+            else:
+                netif = rt[5+mtu_present+prio_present]
         if flg.find("Lc") >= 0:
             continue                
         if dest == "default":
