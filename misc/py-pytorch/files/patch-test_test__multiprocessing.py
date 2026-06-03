--- test/test_multiprocessing.py.orig	2026-04-19 00:27:38 UTC
+++ test/test_multiprocessing.py
@@ -33,7 +33,7 @@ TEST_REPEATS = 30
 load_tests = load_tests  # noqa: PLW0127
 
 TEST_REPEATS = 30
-HAS_SHM_FILES = os.path.isdir("/dev/shm")
+HAS_SHM_FILES = os.path.isdir("/dev/shm") and not sys.platform.startswith("freebsd")
 MAX_WAITING_TIME_IN_SECONDS = 30
 
 TEST_CUDA_IPC = (
@@ -497,7 +497,8 @@ class TestMultiprocessing(TestCase):
         simple_autograd_function()
         # Autograd only uses thread when GPUs are involved
         if (
-            torch.cuda.is_available()
+            sys.platform.startswith("freebsd")
+            or torch.cuda.is_available()
             or torch.backends.mps.is_available()
             or torch.xpu.is_available()
         ):
