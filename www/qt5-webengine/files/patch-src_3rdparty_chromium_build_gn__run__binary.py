--- src/3rdparty/chromium/build/gn_run_binary.py.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/build/gn_run_binary.py
@@ -24,7 +24,7 @@ args = [path] + sys.argv[2:]
 # The rest of the arguments are passed directly to the executable.
 args = [path] + sys.argv[2:]
 
-ret = subprocess.call(args)
+ret = subprocess.call(args, env={"CHROME_EXE_PATH":"${WRKSRC}/out/Release/chrome"})
 if ret != 0:
   if ret <= -100:
     # Windows error codes such as 0xC0000005 and 0xC0000409 are much easier to
