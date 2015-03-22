--- setup.py~
+++ setup.py
@@ -138,12 +138,13 @@
 # Mac OS-X 10.6 is too old.
 
 try:
-    sp = subprocess.Popen(['as', '-v'], stdin=subprocess.PIPE,
+    sp = subprocess.Popen((os.getenv('CXX') or 'c++').split(' ') + (os.getenv('CXXFLAGS') or '').split(' ') + ['-xc', '-c', '-', '-o', '/dev/null', '-Wa,-v'], stdin=subprocess.PIPE,
                           stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                           universal_newlines=True)
     sp.stdin.close()
     sp.wait()
+    as_version=sp.stderr.read()
-    if re.search("GNU assembler version (0|1|2.0)", sp.stderr.read()):
+    if not re.search("GNU assembler", as_version) or re.search("version (0|1|2.0)", as_version):
         define_macros.append(('CRYPTOPP_DISABLE_ASM', 1))
 except EnvironmentError:
     # Okay, nevermind. Maybe there isn't even an 'as' executable on this
