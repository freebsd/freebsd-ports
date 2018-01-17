--- numpy/distutils/exec_command.py.orig	2017-09-29 20:10:10 UTC
+++ numpy/distutils/exec_command.py
@@ -231,7 +231,7 @@ def _exec_command(command, use_shell=Non
 
     if os.name == 'posix' and use_shell:
         # On POSIX, subprocess always uses /bin/sh, override
-        sh = os.environ.get('SHELL', '/bin/sh')
+        sh = '/bin/sh'
         if is_sequence(command):
             command = [sh, '-c', ' '.join(command)]
         else:
