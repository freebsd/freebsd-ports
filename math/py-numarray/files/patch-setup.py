--- setup.py.orig	2005-11-17 23:12:49 UTC
+++ setup.py
@@ -227,6 +227,4 @@ def main():
 # Do the installation.
 #
 if __name__ == "__main__":
-  if "config" not in sys.argv and ("build" in sys.argv or "install" in sys.argv):
-    sys.argv.insert(sys.argv.index("setup.py")+1, "config")
   main()
