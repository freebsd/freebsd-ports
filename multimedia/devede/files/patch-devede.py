--- devede.py.orig	2009-05-25 09:50:34.000000000 -0300
+++ devede.py	2009-06-13 08:40:49.000000000 -0300
@@ -69,7 +69,19 @@
 	except:
 		found=False	
 
-if tipo==0:
+tipo=3
+
+if tipo==3:
+	share_locale="%%PREFIX%%/share/locale"
+	glade="%%DATADIR%%"
+	sys.path.append("%%PREFIX%%/lib/%%PORTNAME%%")
+	font_path="%%DATADIR%%"
+	pic_path="%%DATADIR%%"
+	other_path="%%DATADIR%%"
+	help_path="%%DOCSDIR%%"
+	print "Using port-installed files"
+
+elif tipo==0:
 	#gettext.bindtextdomain('devede', '/usr/share/locale')
 	#Note also before python 2.3 you need the following if
 	#you need translations from non python code (glibc,libglade etc.)
