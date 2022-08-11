https://github.com/secure-systems-lab/securesystemslib/pull/403

--- tests/test_process.py.orig	2022-02-10 09:48:17 UTC
+++ tests/test_process.py
@@ -39,7 +39,7 @@ class Test_Process(unittest.TestCase):
 
     stdin_file = open(path)
     cmd = \
-        "python -c \"import sys; assert(sys.stdin.read() == '{}')\""
+        sys.executable + " -c \"import sys; assert(sys.stdin.read() == '{}')\""
 
     # input is used in favor of stdin
     securesystemslib.process.run(cmd.format("use input kwarg"),
@@ -58,7 +58,7 @@ class Test_Process(unittest.TestCase):
   def test_run_duplicate_streams(self):
     """Test output as streams and as returned.  """
     # Command that prints 'foo' to stdout and 'bar' to stderr.
-    cmd = ("python -c \""
+    cmd = (sys.executable + " -c \""
         "import sys;"
         "sys.stdout.write('foo');"
         "sys.stderr.write('bar');\"")
@@ -102,7 +102,7 @@ class Test_Process(unittest.TestCase):
 
   def test_run_cmd_arg_return_code(self):
     """Test command arg as string and list using return code. """
-    cmd_str = ("python -c \""
+    cmd_str = (sys.executable + " -c \""
         "import sys;"
         "sys.exit(100)\"")
     cmd_list = shlex.split(cmd_str)
@@ -118,7 +118,7 @@ class Test_Process(unittest.TestCase):
   def test_run_duplicate_streams_timeout(self):
     """Test raise TimeoutExpired. """
     with self.assertRaises(securesystemslib.process.subprocess.TimeoutExpired):
-      securesystemslib.process.run_duplicate_streams("python --version",
+      securesystemslib.process.run_duplicate_streams(sys.executable + " --version",
           timeout=-1)
 
 
