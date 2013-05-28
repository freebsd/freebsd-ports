--- rpy.py
+++ rpy.py
@@ -139,6 +139,7 @@ if VERBOSE:
 
 # Version
 from rpy_version import rpy_version
+__version__ = rpy_version
 
 # Symbolic names for conversion modes
 TOP_CONVERSION = 4
diff --git rpy_tools.py rpy_tools.py
index f312201..6e83321 100644
