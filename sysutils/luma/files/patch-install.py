--- install.py.orig	Tue May 18 22:01:47 2004
+++ install.py	Wed Jun  2 22:09:53 2004
@@ -137,6 +137,7 @@
     helpString = """Install options:
  --prefix=PATH \t\t Install path (e.g. /usr/local)
  --compile-only \t Just compile source files. No installation.
+ build \t The same as --compile-only
  \n"""
     print helpString
     sys.exit(1)
@@ -166,7 +167,7 @@
         return
         
     for x in sys.argv[1:]:
-        if x == "--compile-only":
+        if (x == "--compile-only") or (x == "build"):
             global compileOnly
             compileOnly = True
         elif x[:9] == "--prefix=":
@@ -174,7 +175,7 @@
             prefixDir = x[9:]
             if (prefixDir[-1] == "/") and (len(prefixDir) > 1):
                 prefixDir = prefixDir[:-1]
-        else:
+        elif x != "install":
             print "Unknown options. Exiting..."
             sys.exit(1)
 
