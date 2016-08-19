--- lshell/shellcmd.py.orig	2013-09-07 23:07:08 UTC
+++ lshell/shellcmd.py
@@ -134,7 +134,7 @@ class ShellCmd(cmd.Cmd, object):
                 self.g_arg = ' '.join(self.g_line.split()[1:])
                 self.cd()
             else:
-                os.system('set -m; %s' % self.g_line)
+                os.system('%s' % self.g_line)
         elif self.g_cmd not in ['', '?', 'help', None]: 
             self.log.warn('INFO: unknown syntax -> "%s"' %self.g_line)
             self.stderr.write('*** unknown syntax: %s\n' %self.g_cmd)
