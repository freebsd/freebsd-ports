--- flyback.py.orig	2007-11-15 07:22:16.000000000 +0100
+++ flyback.py	2008-01-21 22:17:40.000000000 +0100
@@ -592,6 +592,7 @@
         stdin, stdout = os.popen4('crontab -l')
         for line in stdout:
             if line.startswith('no crontab for'): continue
+            if line.startswith('crontab: no crontab for'): continue
             if line.endswith('#flyback\n'): continue
             existing_crons.append(line)
         if c:
