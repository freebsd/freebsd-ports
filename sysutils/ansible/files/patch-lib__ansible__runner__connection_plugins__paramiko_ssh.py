--- ./lib/ansible/runner/connection_plugins/paramiko_ssh.py.orig	2014-05-23 16:37:57.000000000 -0400
+++ ./lib/ansible/runner/connection_plugins/paramiko_ssh.py	2014-05-31 09:13:44.137967396 -0400
@@ -31,6 +31,7 @@
 import logging
 import traceback
 import fcntl
+import re
 import sys
 from termios import tcflush, TCIFLUSH
 from binascii import hexlify
@@ -210,12 +211,17 @@
                 shcmd, prompt, success_key = utils.make_sudo_cmd(sudo_user, executable, cmd)
             elif self.runner.su or su:
                 shcmd, prompt, success_key = utils.make_su_cmd(su_user, executable, cmd)
+                prompt_re = re.compile(prompt)
             vvv("EXEC %s" % shcmd, host=self.host)
             sudo_output = ''
             try:
                 chan.exec_command(shcmd)
                 if self.runner.sudo_pass or self.runner.su_pass:
-                    while not sudo_output.endswith(prompt) and success_key not in sudo_output:
+                    while True:
+                        if success_key in sudo_output or \
+                            (self.runner.sudo_pass and sudo_output.endswith(prompt)) or \
+                            (self.runner.su_pass and prompt_re.match(sudo_output)):
+                            break
                         chunk = chan.recv(bufsize)
                         if not chunk:
                             if 'unknown user' in sudo_output:
