--- build/linux/strip_binary.py.orig	2026-10-31 12:09:36 UTC
+++ build/linux/strip_binary.py
@@ -10,6 +10,7 @@ import sys
 
 
 def main() -> int:
+    return 0
     parser = argparse.ArgumentParser(
         description="Strip binary using LLVM tools."
     )
