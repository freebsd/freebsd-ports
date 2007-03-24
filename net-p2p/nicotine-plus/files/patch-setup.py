--- setup.py	Sat Mar 24 07:31:17 2007
+++ setup.py	Sat Mar 24 07:33:11 2007
@@ -27,12 +27,12 @@
 		files.append((os.path.join(sys.prefix, "share", "nicotine", "sounds", theme), [os.path.join(sounds, file)]))
 doc_files = glob.glob(os.path.join("doc", "*"))
 for file in doc_files:
-	files.append((os.path.join(sys.prefix, "share", "nicotine", "documentation"), [file]))
+	files.append((os.path.join(sys.prefix, "share", "doc", "nicotine"), [file]))
 files.append((os.path.join(sys.prefix, "share", "applications"), ["files/nicotine.desktop"]))
 # Manuals
 manpages = glob.glob(os.path.join("manpages", "*.1"))
 for man in manpages:
-	files.append((os.path.join(sys.prefix, "share", "man", "man1"), [man]))
+	files.append((os.path.join(sys.prefix, "man", "man1"), [man]))
 files.append((os.path.join(sys.prefix, "share", "pixmaps"), ["files/nicotine-plus-32px.png"]))
 if sys.platform.startswith("win"):
   try:
