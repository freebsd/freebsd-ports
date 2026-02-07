--- psi4/run_psi4.py.orig	2022-12-06 22:09:19 UTC
+++ psi4/run_psi4.py
@@ -37,6 +37,8 @@ import sys
 import warnings
 from pathlib import Path
 
+os.environ["PSIDATADIR"] = "%%DATADIR%%"
+
 # yapf: disable
 parser = argparse.ArgumentParser(description="Psi4: Open-Source Quantum Chemistry", formatter_class=argparse.RawTextHelpFormatter)
 parser.add_argument("-i", "--input", default="input.dat",
@@ -126,7 +128,7 @@ if args["inplace"]:
 
     lib_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
     if ("PSIDATADIR" not in os.environ.keys()) and (not args["psidatadir"]):
-        data_dir = os.path.sep.join([os.path.abspath(os.path.dirname(__file__)), "share", "psi4"])
+        data_dir = "%%DATADIR%%"
         os.environ["PSIDATADIR"] = data_dir
 
 elif "CMAKE_INSTALL_LIBDIR" in lib_dir:
