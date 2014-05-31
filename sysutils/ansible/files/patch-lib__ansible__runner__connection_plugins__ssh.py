--- ./lib/ansible/runner/connection_plugins/ssh.py.orig	2014-05-23 16:37:57.000000000 -0400
+++ ./lib/ansible/runner/connection_plugins/ssh.py	2014-05-31 09:13:44.138967431 -0400
@@ -17,6 +17,7 @@
 #
 
 import os
+import re
 import subprocess
 import shlex
 import pipes
@@ -263,6 +264,7 @@
 
         if su and su_user:
             sudocmd, prompt, success_key = utils.make_su_cmd(su_user, executable, cmd)
+            prompt_re = re.compile(prompt)
             ssh_cmd.append(sudocmd)
         elif not self.runner.sudo or not sudoable:
             prompt = None
@@ -303,7 +305,12 @@
             sudo_output = ''
             sudo_errput = ''
 
-            while not sudo_output.endswith(prompt) and success_key not in sudo_output:
+            while True:
+                if success_key in sudo_output or \
+                    (self.runner.sudo_pass and sudo_output.endswith(prompt)) or \
+                    (self.runner.su_pass and prompt_re.match(sudo_output)):
+                    break
+
                 rfd, wfd, efd = select.select([p.stdout, p.stderr], [],
                                               [p.stdout], self.runner.timeout)
                 if p.stderr in rfd:
