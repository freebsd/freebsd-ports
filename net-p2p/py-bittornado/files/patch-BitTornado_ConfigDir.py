
$FreeBSD$

--- BitTornado/ConfigDir.py.orig	Tue May 25 09:55:49 2004
+++ BitTornado/ConfigDir.py	Tue May 25 09:56:59 2004
@@ -15,7 +15,7 @@
     True = 1
     False = 0
 
-OLDICONPATH = os.path.abspath(os.path.dirname(os.path.realpath(sys.argv[0])))
+OLDICONPATH="%%PREFIX%%/share/BitTornado"
 
 DIRNAME = '.'+product_name
 
