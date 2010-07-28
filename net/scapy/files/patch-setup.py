--- setup.py	2010-04-10 02:42:04.000000000 +0400
+++ setup.py	2010-07-22 21:17:18.000000000 +0400
@@ -42,7 +42,7 @@
 setup(
     name = 'scapy',
     version = '2.1.1',
-    packages=['scapy','scapy/arch', 'scapy/arch/windows', 'scapy/layers','scapy/asn1','scapy/tools','scapy/modules', 'scapy/crypto'],
+    packages=['scapy','scapy/arch', 'scapy/layers','scapy/asn1','scapy/tools','scapy/modules', 'scapy/crypto'],
     scripts = SCRIPTS,
     data_files = [('share/man/man1', ["doc/scapy.1.gz"])],
 
