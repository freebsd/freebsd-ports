--- fax/backend/hpfax.py.orig	2022-02-23 07:41:04 UTC
+++ fax/backend/hpfax.py
@@ -49,7 +49,7 @@ PIPE_BUF = 4096
 
 job_id = 0
 pid = os.getpid()
-config_file = '/etc/hp/hplip.conf'
+config_file = '/usr/local/etc/hp/hplip.conf'
 home_dir = ''
 
 
@@ -68,7 +68,7 @@ if os.path.exists(config_file):
         bug("Error setting home directory: home= under [dirs] not found.")
         sys.exit(1)
 else:
-    bug("Error setting home directory: /etc/hp/hplip.conf not found")
+    bug("Error setting home directory: /usr/local/etc/hp/hplip.conf not found")
     sys.exit(1)
 
 if not home_dir or not os.path.exists(home_dir):
@@ -255,7 +255,7 @@ else:
 
     # Create the named pipe. Make sure it exists before sending
     # message to hppsd.
-    os.umask(0o111)
+    os.umask(0o133)
     try:
         os.mkfifo(pipe_name)
     except OSError:
