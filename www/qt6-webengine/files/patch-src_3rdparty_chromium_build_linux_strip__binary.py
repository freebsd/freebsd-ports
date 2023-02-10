--- src/3rdparty/chromium/build/linux/strip_binary.py.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/build/linux/strip_binary.py
@@ -10,6 +10,7 @@ def main():
 
 
 def main():
+  return 0
   argparser = argparse.ArgumentParser(description='eu-strip binary.')
 
   argparser.add_argument('--eu-strip-binary-path', help='eu-strip path.')
