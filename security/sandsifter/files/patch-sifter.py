--- sifter.py.orig	2019-07-31 14:21:48 UTC
+++ sifter.py
@@ -59,7 +59,7 @@ class InjectorResults(Structure):
                 ('signum', c_int),
                 ('sicode', c_int),
                 ('siaddr', c_int),
-		]
+                ]
 
 class Settings:
     SYNTH_MODE_RANDOM = "r"
@@ -643,8 +643,8 @@ class Gui:
                         # red.  doesn't happen if using a new random string each
                         # time; doesn't happen if using a constant string each
                         # time.  only happens with the specific implementation below.
-						#TODO: on systems with limited color settings, this
-						# makes the background look like random characters
+                                                #TODO: on systems with limited color settings, this
+                                                # makes the background look like random characters
                         random_string = ("%02x" % random.randint(0,100)) * (raw_width-2)
                         self.stdscr.addstr(top + 1 + y, left, random_string, curses.color_pair(self.BLACK))
 
@@ -709,7 +709,7 @@ class Gui:
 
 def get_cpu_info():
     cpu_path = "/proc/cpuinfo"
-    if platform.system == "FreeBSD":
+    if platform.system() == "FreeBSD":
         cpu_path = "/compat/linux%s" % cpu_path
     with open(cpu_path, "r") as f:
         cpu = [l.strip() for l in f.readlines()[:7]]
@@ -790,7 +790,8 @@ def main():
         # Pick the first valid injector entry, this is not ideal but it should work fine
         INJECTOR = INJECTOR[0]
         print("Using injector from: %s" % INJECTOR)
-        print("Injector BuildID: %s" % subprocess.check_output(['eu-readelf', '-n', INJECTOR]).split()[-1])
+        if platform.system() != "FreeBSD":
+            print("Injector BuildID: %s" % subprocess.check_output(['eu-readelf', '-n', INJECTOR]).split()[-1])
         
 
     parser = argparse.ArgumentParser()
@@ -851,7 +852,7 @@ def main():
         TICK = os.path.join(OUTPUT, "tick")
         LAST = os.path.join(OUTPUT, "last")
     else:
-	print("warning: no log output path (--out) specified, results will be recorded to %s \nManualy specify a (--out) output path if you want your results recorded elsewhere." % OUTPUT)
+        print("warning: no log output path (--out) specified, results will be recorded to %s \nManualy specify a (--out) output path if you want your results recorded elsewhere." % OUTPUT)
         # Wait to show message to user.
         time.sleep(3)
         # Create /tmp directory if it does not exist already, here we use much less strict checks.
