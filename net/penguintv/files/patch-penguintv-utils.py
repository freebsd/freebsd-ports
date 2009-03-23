--- penguintv/utils.py.orig	2009-03-23 08:35:01.000000000 +1100
+++ penguintv/utils.py	2009-03-23 08:35:31.000000000 +1100
@@ -228,7 +228,8 @@
 		  os.path.join(os.path.split(os.path.abspath(sys.argv[0]))[0],"share"),
 		  os.path.join(GetPrefix(),"share","sugar","activities","ptv","share"),
 		  os.path.join(os.path.split(os.path.split(utils.__file__)[0])[0],'share','glade'),
-		  "/usr/share/penguintv/glade"):
+		  "/usr/share/penguintv/glade",
+		  "%%LOCALBASE%%/penguintv/glade"):
 		try:
 			os.stat(os.path.join(p,"dialogs.glade"))
 			logging.debug("glade prefix found: %s" % (p,))
