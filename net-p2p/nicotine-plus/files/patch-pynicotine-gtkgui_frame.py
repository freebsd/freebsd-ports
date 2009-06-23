--- pynicotine/gtkgui/frame.py	2009-05-25 06:09:14.000000000 -0500
+++ pynicotine/gtkgui/frame.py	2009-06-23 13:46:11.000000000 -0500
@@ -2605,18 +2605,18 @@
 			paths.append(path1split[0])
 		else:
 			paths.append(path1)
-		path2 = "%s/share/nicotine/documentation" % sys.prefix
+		path2 = "%s/share/doc/nicotine" % sys.prefix
 		paths.append(path2)
 		winpath = "C:\Program Files\Nicotine+" 
 		paths.append(winpath)
 		for path in paths:
-			if os.path.exists(os.sep.join([path, "doc", file])):
-				url = "file:%s/%s/%s" % (urllib.pathname2url(path).replace("|", ":") ,"doc", file)
+			if os.path.exists(os.sep.join([path, "documentation", file])):
+				url = "file:%s/%s/%s" % (urllib.pathname2url(path).replace("|", ":") ,"documentation", file)
 
 				self.OpenUrl(url)
 				return
 		else:
-			popupWarning(None, _("Cannot Find Guide"), _("The Nicotine Offline Guide ( NicotinePlusGuide.html ) was not found in either the following directories:\n\n<u>%(pwd)s\n</u><b>and</b>\n<u>%(prefix)s/share/nicotine/documentation/</u>\n\nEither install Nicotine-Plus, or start from inside the Nicotine-Plus source directory." % {'pwd':path1, 'prefix':sys.prefix } ) )
+			popupWarning(None, _("Cannot Find Guide"), _("The Nicotine Offline Guide ( NicotinePlusGuide.html ) was not found in either the following directories:\n\n<u>%(pwd)s\n</u><b>and</b>\n<u>%(prefix)s/share/doc/nicotine/documentation/</u>\n\nEither install Nicotine-Plus, or start from inside the Nicotine-Plus source directory." % {'pwd':path1, 'prefix':sys.prefix } ) )
 	
 	def OnOnlineNicotineGuide(self, widget):
 		url = "http://nicotine-plus.sourceforge.net/NicotinePlusGuide/"
