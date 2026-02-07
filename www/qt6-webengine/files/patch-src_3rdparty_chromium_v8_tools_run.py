--- src/3rdparty/chromium/v8/tools/run.py.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/v8/tools/run.py
@@ -21,7 +21,7 @@ if cmd and cmd[0] == '--redirect-stdout':
   kwargs = dict(stdout=subprocess.PIPE)
   cmd = cmd[2:]
 
-process = subprocess.Popen(cmd, **kwargs)
+process = subprocess.Popen(cmd, env={"LD_LIBRARY_PATH":"${WRKSRC}/out/Release"}, **kwargs)
 stdout, _ = process.communicate()
 if stdout_file:
   with stdout_file.open('w') as f:
