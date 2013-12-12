--- setup.py.orig	2013-12-12 18:04:59.679796972 -0200
+++ setup.py	2013-12-12 18:05:04.376796310 -0200
@@ -227,6 +227,4 @@
 # Do the installation.
 #
 if __name__ == "__main__":
-  if "config" not in sys.argv and ("build" in sys.argv or "install" in sys.argv):
-    sys.argv.insert(sys.argv.index("setup.py")+1, "config")
   main()
