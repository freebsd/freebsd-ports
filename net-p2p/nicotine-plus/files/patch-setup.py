--- setup.py	2009-05-22 14:59:23.000000000 -0500
+++ setup.py	2009-06-23 13:14:20.000000000 -0500
@@ -84,7 +84,7 @@
 	# Manuals
 	manpages = glob.glob(os.path.join("manpages", "*.1"))
 	for man in manpages:
-		files.append((os.path.join(sys.prefix, "share", "man", "man1"), [man]))
+		files.append((os.path.join(sys.prefix, "man", "man1"), [man]))
 	files.append((os.path.join(sys.prefix, "share", "pixmaps"), ["files/nicotine-plus-32px.png"]))
 	files.append((os.path.join(sys.prefix, "share", "applications"), ["files/nicotine.desktop"]))
 
@@ -115,7 +115,7 @@
 	if is_windows:
 		files.append((os.path.join("share", "nicotine", "documentation"), [file]))
 	else:
-		files.append((os.path.join(sys.prefix, "share", "nicotine", "documentation"), [file]))
+		files.append((os.path.join(sys.prefix, "share", "doc", "nicotine", "documentation"), [file]))
 
 # Glade files (GUI)
 #glade_files = glob.glob(os.path.join("pynicotine", "gtkgui", "*.glade"))
