--- build_tools/scripts/config.py.orig	2025-10-15 14:25:47 UTC
+++ build_tools/scripts/config.py
@@ -26,6 +26,7 @@
   global platforms
   platforms = ["win_64", "win_32", "win_64_xp", "win_32_xp", "win_arm64", 
                "linux_64", "linux_32", "linux_arm64",
+               "freebsd_64",
                "mac_64", "mac_arm64",
                "ios", 
                "android_arm64_v8a", "android_armv7", "android_x86", "android_x86_64"]
@@ -39,6 +40,8 @@
       options["platform"] += " win_64 win_32"
     elif ("linux" == host_platform):
       options["platform"] += " linux_64 linux_32"
+    elif ("freebsd" == host_platform):
+      options["platform"] += " freebsd_64"
     else:
       options["platform"] += " mac_64"
 
@@ -50,6 +53,8 @@
       options["platform"] += (" win_" + bits)
     elif ("linux" == host_platform):
       options["platform"] += (" linux_" + bits)
+    elif ("freebsd" == host_platform):
+      options["platform"] += (" freebsd_" + bits)
     else:
       options["platform"] += (" mac_" + bits)
 
@@ -176,6 +181,9 @@
     if (0 == platform.find("win_arm")):
       compiler["compiler"] = "msvc" + options["vs-version"] + "_arm"
       compiler["compiler_64"] = "msvc" + options["vs-version"] + "_arm64"
+  elif (0 == platform.find("freebsd")):
+    compiler["compiler"] = "clang"
+    compiler["compiler_64"] = "clang_64"
   elif (0 == platform.find("linux")):
     compiler["compiler"] = "gcc"
     compiler["compiler_64"] = "gcc_64"
