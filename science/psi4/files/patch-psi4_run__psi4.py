--- psi4/run_psi4.py.orig	2025-09-05 14:52:21 UTC
+++ psi4/run_psi4.py
@@ -38,6 +38,8 @@ from pathlib import Path
 import warnings
 from pathlib import Path
 
+os.environ["PSIDATADIR"] = "/usr/local/share/psi4"
+
 # yapf: disable
 parser = argparse.ArgumentParser(description="Psi4: Open-Source Quantum Chemistry", formatter_class=argparse.RawTextHelpFormatter)
 parser.add_argument("-i", "--input", default="input.dat",
@@ -162,7 +164,7 @@ if args["inplace"]:
 
     lib_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
     if ("PSIDATADIR" not in os.environ.keys()) and (not args["psidatadir"]):
-        data_dir = os.path.sep.join([os.path.abspath(os.path.dirname(__file__)), "share", "psi4"])
+        data_dir = "/usr/local/share/psi4"
         os.environ["PSIDATADIR"] = data_dir
 
 elif "CMAKE_INSTALL_LIBDIR" in lib_dir:
