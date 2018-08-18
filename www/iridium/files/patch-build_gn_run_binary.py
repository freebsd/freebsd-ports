--- build/gn_run_binary.py.orig	2017-12-30 01:00:32.419195000 +0100
+++ build/gn_run_binary.py	2017-12-30 01:01:14.497716000 +0100
@@ -19,7 +19,7 @@
 # The rest of the arguments are passed directly to the executable.
 args = [path] + sys.argv[2:]
 
-ret = subprocess.call(args)
+ret = subprocess.call(args, env={"CHROME_EXE_PATH":"${WRKSRC}/out/Release/chrome"})
 if ret != 0:
   print '%s failed with exit code %d' % (sys.argv[1], ret)
 sys.exit(ret)
