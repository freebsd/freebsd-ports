--- install.py.orig	Mon Dec 13 00:45:57 2004
+++ install.py	Tue Dec 14 13:28:05 2004
@@ -99,26 +99,15 @@
     print "Copy program files...\n"
     
     try:
-        a = Popen3("cp -R bin " + prefixDir)
-        while a.poll() == -1:
-            pass
-        if a.poll() > 0:
-            raise "CopyError", "Error!!! Could not copy File. Maybe wrong permissions?"
+	for idir in ["bin", "lib", "share", "man"]:
+		a = Popen3("cp -R " + idir + " " + prefixDir)
+		while a.poll() == -1:
+			pass
+			if a.poll() > 0:
+				raise "CopyError", "Error!!! Could not copy File. Maybe wrong permissions?"
 
-        a = Popen3("cp -R lib " + prefixDir)
-        while a.poll() == -1:
-            pass
-        if a.poll() > 0:
-            raise "CopyError", "Error!!! Could not copy File. Maybe wrong permissions?"
-
-        a = Popen3("cp -R share " + prefixDir)
-        while a.poll() == -1:
-            pass
-        if a.poll() > 0:
-            raise "CopyError", "Error!!! Could not copy File. Maybe wrong permissions?"
-
-        print "Finished copying program files.\n"
-        print "LUMA installed succesfully! :)"
+	print "Finished copying program files.\n"
+	print "LUMA installed succesfully! :)"
         
     except "CopyError", errorMessage:
         print errorMessage
@@ -157,6 +146,7 @@
     helpString = """Install options:
  --prefix=PATH \t\t Install path (default is /usr/local)
  --compile-only \t Just compile source files. No installation.
+ build \t The same as --compile-only
  \n"""
  
     print helpString
@@ -194,7 +184,7 @@
         return
         
     for x in sys.argv[1:]:
-        if x == "--compile-only":
+        if (x == "--compile-only") or (x == "build"):
             global compileOnly
             compileOnly = True
         elif x[:9] == "--prefix=":
@@ -202,7 +192,7 @@
             prefixDir = x[9:]
             if (prefixDir[-1] == "/") and (len(prefixDir) > 1):
                 prefixDir = prefixDir[:-1]
-        else:
+        elif x != "install":
             print "Unknown options. Exiting..."
             sys.exit(1)
 
