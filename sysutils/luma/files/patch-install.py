--- install.py.orig	Wed Mar 16 13:36:15 2005
+++ install.py	Wed Mar 16 13:40:43 2005
@@ -99,7 +99,7 @@
     print "Copy program files...\n"
     
     try:
-        for tmpDir in ["bin", "lib", "share"]:
+        for tmpDir in ["bin", "lib", "share", "man"]:
             a = Popen3("cp -R " + tmpDir + " " + prefixDir)
             while a.poll() == -1:
                 pass
@@ -146,6 +146,7 @@
     helpString = """Install options:
  --prefix=PATH \t\t Install path (default is /usr/local)
  --compile-only \t Just compile source files. No installation.
+ build \t The same as --compile-only
  \n"""
  
     print helpString
@@ -183,7 +184,7 @@
         return
         
     for x in sys.argv[1:]:
-        if x == "--compile-only":
+        if x == "--compile-only" or x == "build":
             global compileOnly
             compileOnly = True
         elif x[:9] == "--prefix=":
@@ -191,7 +192,7 @@
             prefixDir = x[9:]
             if (prefixDir[-1] == "/") and (len(prefixDir) > 1):
                 prefixDir = prefixDir[:-1]
-        else:
+        elif x != "install":
             print "Unknown options. Exiting..."
             sys.exit(1)
 
