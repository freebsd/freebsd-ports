--- test/test_multiprocessing.py.orig	2026-10-28 18:13:31 UTC
+++ test/test_multiprocessing.py
@@ -41,7 +41,7 @@ TEST_REPEATS = 30
 load_tests = load_tests  # noqa: PLW0127
 
 TEST_REPEATS = 30
-HAS_SHM_FILES = os.path.isdir("/dev/shm")
+HAS_SHM_FILES = os.path.isdir("/dev/shm") and not sys.platform.startswith("freebsd")
 MAX_WAITING_TIME_IN_SECONDS = 30
 
 TEST_CUDA_IPC = (
