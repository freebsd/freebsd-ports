--- cargo-crates/v8-150.4.0/build/linux/strip_binary.py.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/build/linux/strip_binary.py
@@ -10,6 +10,7 @@ def main() -> int:
 
 
 def main() -> int:
+  return 0
   parser = argparse.ArgumentParser(description="Strip binary using LLVM tools.")
   parser.add_argument("--llvm-strip-binary-path",
                       help="Path to llvm-strip executable.")
