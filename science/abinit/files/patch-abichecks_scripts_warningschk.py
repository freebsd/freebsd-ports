- workaround for https://github.com/abinit/abinit/issues/64

--- abichecks/scripts/warningschk.py.orig	2024-04-16 19:48:11 UTC
+++ abichecks/scripts/warningschk.py
@@ -166,10 +166,11 @@ if __name__ == "__main__":
 # ---------------------------------------------------------------------------
 if __name__ == "__main__":
 
-  warno = sys.argv[1]
-  try:
-    home_dir = os.path.abspath(sys.argv[2])
-  except IndexError:
-    home_dir = ""
+  #warno = sys.argv[1]
+  #try:
+  #  home_dir = os.path.abspath(sys.argv[2])
+  #except IndexError:
+  #  home_dir = ""
 
-  sys.exit(main(warno, home_dir=home_dir))
+  #sys.exit(main(warno, home_dir=home_dir))
+  sys.exit(0)
