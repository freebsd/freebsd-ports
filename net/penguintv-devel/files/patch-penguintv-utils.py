--- penguintv/utils.py.orig	2008-03-13 21:59:27.000000000 +0000
+++ penguintv/utils.py	2008-03-13 22:00:06.000000000 +0000
@@ -186,6 +186,7 @@
 		  os.path.join(os.path.split(os.path.abspath(sys.argv[0]))[0],"share"),
 		  os.path.join(GetPrefix(),"share","sugar","activities","ptv","share"),
 		  os.path.join(os.path.split(os.path.split(utils.__file__)[0])[0],'share'),
+		  "/usr/local/share/penguintv",
 		  "/usr/share/penguintv"):
 		try:
 			os.stat(os.path.join(p,"penguintv.glade"))
