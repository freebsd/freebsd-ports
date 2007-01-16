--- setup.py.orig	Tue Jan 16 10:27:25 2007
+++ setup.py	Tue Jan 16 10:28:04 2007
@@ -27,7 +27,7 @@
 		files.append((os.path.join(sys.prefix, "share", "nicotine", "sounds", theme), [os.path.join(sounds, file)]))
 doc_files = glob.glob(os.path.join("doc", "*"))
 for file in doc_files:
-	files.append((os.path.join(sys.prefix, "share", "nicotine", "documentation"), [file]))
+	files.append((os.path.join(sys.prefix, "share", "doc", "nicotine"), [file]))
 files.append((os.path.join(sys.prefix, "share", "applications"), ["files/nicotine.desktop"]))
 files.append((os.path.join(sys.prefix, "share", "pixmaps"), ["files/nicotine-plus-32px.png"]))
 if sys.platform.startswith("win"):
