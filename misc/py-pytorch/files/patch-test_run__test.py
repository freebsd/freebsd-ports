--- test/run_test.py.orig	2026-05-13 17:40:38 UTC
+++ test/run_test.py
@@ -1155,6 +1155,12 @@ def run_doctests(test_module, test_directory, options)
         else:
             enabled["onnx"] = True
 
+    try:
+        import torchdata.datapipes  # NOQA: F401
+    except ImportError:
+        # torchdata.datapipes was removed in newer versions; skip datapipes doctests
+        exclude_module_list.append("torch.utils.data.datapipes.*")
+
     # Set doctest environment variables
     if enabled["cuda"]:
         os.environ["TORCH_DOCTEST_CUDA"] = "1"
@@ -1869,6 +1875,35 @@ def get_selected_tests(options) -> list[str]:
             "Skip distributed tests on s390x",
         )
 
+    if sys.platform.startswith("freebsd"):
+        selected_tests = exclude_tests(
+            ["profiler/test_profiler", "dynamo/test_profiler"],
+            selected_tests,
+            "Skip profiler tests on FreeBSD (Kineto causes SIGABRT)",
+        )
+        selected_tests = exclude_tests(
+            DISTRIBUTED_TESTS,
+            selected_tests,
+            "Skip distributed tests on FreeBSD (Gloo does not support FreeBSD)",
+        )
+        selected_tests = exclude_tests(
+            ["test_ci_sanity_check_fail"],
+            selected_tests,
+            "Skip CI-only sanity check on FreeBSD (requires CI env var)",
+        )
+        selected_tests = exclude_tests(
+            [
+                "cpp_extensions/libtorch_agn_2_10_extension/test_version_compatibility",
+            ],
+            selected_tests,
+            "Skip g++ version-compatibility tests on FreeBSD (g++ not available)",
+        )
+        selected_tests = exclude_tests(
+            ["test_vulkan"],
+            selected_tests,
+            "Skip Vulkan tests on FreeBSD (SIGSEGV in Vulkan driver teardown)",
+        )
+
     # skip all distributed tests if distributed package is not available.
     if not dist.is_available():
         selected_tests = exclude_tests(
@@ -2148,7 +2183,7 @@ def check_pip_packages() -> None:
 def check_pip_packages() -> None:
     packages = [
         "pytest-rerunfailures",
-        "pytest-flakefinder",
+        # pytest-flakefinder is not available as a FreeBSD port; skip check
         "pytest-xdist",
     ]
     try:
