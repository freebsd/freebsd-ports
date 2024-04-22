--- third_party/ffmpeg/chromium/scripts/robo_lib/config.py.orig	2024-03-22 14:16:19 UTC
+++ third_party/ffmpeg/chromium/scripts/robo_lib/config.py
@@ -49,18 +49,12 @@ class RoboConfiguration:
     self._llvm_path = os.path.join(self.chrome_src(), "third_party",
             "llvm-build", "Release+Asserts", "bin")
 
-    self.EnsurePathContainsLLVM()
-    self.EnsureNoMakeInfo()
     self.EnsureFFmpegHome()
     self.EnsureASANConfig()
-    self.ComputeBranchName()
     if not quiet:
       shell.log(f"Using chrome src: {self.chrome_src()}")
       shell.log(f"Using script dir: {self._script_directory}")
       shell.log(f"Using ffmpeg home:{self.ffmpeg_home()}")
-      shell.log(f"On branch: {self.branch_name()}")
-      if self.sushi_branch_name():
-        shell.log(f"On sushi branch: {self.sushi_branch_name()}")
 
     # Filename that we'll ask generate_gn.py to write git commands to.
     # TODO: Should this use script_directory, or stay with ffmpeg?  As long as
@@ -152,9 +146,9 @@ class RoboConfiguration:
 
     if re.match(r"i.86", platform.machine()):
       self._host_architecture = "ia32"
-    elif platform.machine() == "x86_64" or platform.machine() == "AMD64":
+    elif platform.machine() == "x86_64" or platform.machine() == "AMD64" or platform.machine() == "amd64":
       self._host_architecture = "x64"
-    elif platform.machine() == "aarch64":
+    elif platform.machine() == "aarch64" or platform.machine() == "arm64":
       self._host_architecture = "arm64"
     elif platform.machine() == "mips32":
       self._host_architecture = "mipsel"
@@ -185,6 +179,10 @@ class RoboConfiguration:
       self._host_operating_system = "mac"
     elif platform.system() == "Windows" or "CYGWIN_NT" in platform.system():
       self._host_operating_system = "win"
+    elif platform.system() == "OpenBSD":
+      self._host_operating_system = "openbsd"
+    elif platform.system() == "FreeBSD":
+      self._host_operating_system = "freebsd"
     else:
       raise ValueError(f"Unsupported platform: {platform.system()}")
 
@@ -193,8 +191,8 @@ class RoboConfiguration:
     wd = os.getcwd()
     # Walk up the tree until we find src/AUTHORS
     while wd != "/":
-      if os.path.isfile(os.path.join(wd, "src", "AUTHORS")):
-        self._chrome_src = os.path.join(wd, "src")
+      if os.path.isfile(os.path.join(wd, "third_party", "DEPS")):
+        self._chrome_src = wd
         return
       wd = os.path.dirname(wd)
     raise Exception("could not find src/AUTHORS in any parent of the wd")
