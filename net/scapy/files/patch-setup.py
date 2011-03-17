--- setup.py.orig	2011-02-28 05:11:55.000000000 +0300
+++ setup.py	2011-03-01 13:11:36.000000000 +0300
@@ -47,7 +47,7 @@
 setup(
     name = 'scapy',
     version = '2.2.0',
-    packages=['scapy','scapy/arch', 'scapy/arch/windows', 'scapy/layers','scapy/asn1','scapy/tools','scapy/modules', 'scapy/crypto'],
+    packages=['scapy','scapy/arch', 'scapy/layers','scapy/asn1','scapy/tools','scapy/modules', 'scapy/crypto'],
     scripts = SCRIPTS,
     data_files = [('share/man/man1', ["doc/scapy.1.gz"])],
 
