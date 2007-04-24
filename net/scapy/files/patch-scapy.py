--- /usr/ports/net/scapy/work/scapy-1.1.1/scapy.py	Mon Apr  9 13:17:35 2007
+++ scapy.py	Sat Apr 21 22:24:12 2007
@@ -482,7 +482,7 @@
         pass
     return manufdb
     
-MANUFDB = load_manuf("/usr/share/wireshark/wireshark/manuf")
+MANUFDB = load_manuf("/usr/local/share/wireshark/manuf")
 
 
 
@@ -11856,9 +11856,9 @@
     BTsocket = BluetoothL2CAPSocket
     histfile = os.path.join(os.environ["HOME"], ".scapy_history")
     padding = 1
-    p0f_base ="/etc/p0f/p0f.fp"
-    queso_base ="/etc/queso.conf"
-    nmap_base ="/usr/share/nmap/nmap-os-fingerprints"
+    p0f_base ="/usr/local/etc/p0f/p0f.fp"
+    queso_base ="/usr/local/etc/queso.conf"
+    nmap_base ="/usr/local/share/nmap/nmap-os-fingerprints"
     IPCountry_base = "GeoIPCountry4Scapy.gz"
     countryLoc_base = "countryLoc.csv"
     gnuplot_world = "world.dat"
