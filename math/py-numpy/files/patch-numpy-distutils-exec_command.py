--- numpy/distutils/exec_command.py.orig	2021-05-08 18:35:28 UTC
+++ numpy/distutils/exec_command.py
@@ -261,7 +261,7 @@ def _exec_command(command, use_shell=None, use_tee = N
 
     if os.name == 'posix' and use_shell:
         # On POSIX, subprocess always uses /bin/sh, override
-        sh = os.environ.get('SHELL', '/bin/sh')
+        sh = '/bin/sh'
         if is_sequence(command):
             command = [sh, '-c', ' '.join(command)]
         else:
