--- pynicotine/gtkgui/frame.py	Tue Jan 16 11:22:06 2007
+++ pynicotine/gtkgui/frame.py	Tue Jan 16 11:23:53 2007
@@ -1235,7 +1235,7 @@
 			url = "file://%s/%s" % (os.environ["PWD"], file)
 			self.OpenUrl(url)
 		else:
-			file = "%s/share/nicotine/documentation/NicotinePlusGuide.html" % sys.prefix
+			file = "%s/share/doc/nicotine/NicotinePlusGuide.html" % sys.prefix
 			if os.path.exists(file):
 				url = "file://%s" % file
 				self.OpenUrl(url)
