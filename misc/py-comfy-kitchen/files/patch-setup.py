--- setup.py.orig	2025-03-01 00:00:00 UTC
+++ setup.py
@@ -21,7 +21,7 @@ from setuptools.command.build_ext import build_ext
 # Parse command-line early to check for --no-cuda flag
 # This needs to happen before get_extensions() is called
 # Usage: python setup.py install --no-cuda
-BUILD_NO_CUDA = False
+BUILD_NO_CUDA = os.getenv("COMFY_KITCHEN_NO_CUDA", "0") == "1"
 if "--no-cuda" in sys.argv:
     BUILD_NO_CUDA = True
     sys.argv.remove("--no-cuda")  # Remove so setuptools doesn't complain
