--- psi4/run_psi4.py.orig	2026-06-30 02:22:36 UTC
+++ psi4/run_psi4.py
@@ -38,6 +38,9 @@ from pathlib import Path
 import warnings
 from pathlib import Path
 
+if "PSIDATADIR" not in os.environ.keys():
+    os.environ["PSIDATADIR"] = "%%DATADIR%%"
+
 # yapf: disable
 parser = argparse.ArgumentParser(description="Psi4: Open-Source Quantum Chemistry", formatter_class=argparse.RawTextHelpFormatter)
 parser.add_argument("-i", "--input", default="input.dat",
@@ -162,7 +165,7 @@ if args["inplace"]:
 
     lib_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
     if ("PSIDATADIR" not in os.environ.keys()) and (not args["psidatadir"]):
-        data_dir = os.path.sep.join([os.path.abspath(os.path.dirname(__file__)), "share", "psi4"])
+        data_dir = "/usr/local/share/psi4"
         os.environ["PSIDATADIR"] = data_dir
 
 elif "CMAKE_INSTALL_LIBDIR" in lib_dir:
