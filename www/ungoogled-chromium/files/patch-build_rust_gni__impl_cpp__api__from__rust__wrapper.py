--- build/rust/gni_impl/cpp_api_from_rust_wrapper.py.orig	2026-11-17 11:49:09 UTC
+++ build/rust/gni_impl/cpp_api_from_rust_wrapper.py
@@ -22,16 +22,25 @@ def main():
     parser.add_argument(
         '--cpp-api-from-rust-exe-path', required=True, type=pathlib.Path
     )
+    # `--rustc-env-and-flags` is not used when generating bindings from
+    # `.rmeta` files (i.e. with `--enable-rmeta-interface=true`).
+    parser.add_argument('--rustc-env-and-flags', type=pathlib.Path)
     parser.add_argument(
-        '--rustc-env-and-flags', type=pathlib.Path, required=True
+        '--extra-rustc-flag',
+        action='append',
+        default=[],
+        help='Appended to the `rustc` flags from `--rustc-env-and-flags`.',
     )
     parser.add_argument('args', metavar='ARG', nargs='+')
     args = parser.parse_args()
 
-    (rustenv, rustflags) = LoadRustEnvAndFlags(args.rustc_env_and_flags)
-    PrepareRustEnvForExecution(rustenv)
+    rustenv = None
+    rustflags = []
+    if args.rustc_env_and_flags:
+        (rustenv, rustflags) = LoadRustEnvAndFlags(args.rustc_env_and_flags)
+        PrepareRustEnvForExecution(rustenv)
 
-    rustflags = [*args.args, "--", *rustflags]
+    rustflags = [*args.args, "--", *rustflags, *args.extra_rustc_flag]
 
     # `cpp_api_from_rust` should not write any files into the build directory
     # (e.g. into `out/`).
