From 3b6fec58dd3e6b070176e0aafcbfed3cb5a0bd18 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Lo=C3=AFc=20Blot?= <nerzhul@users.noreply.github.com>
Date: Sat, 18 Dec 2021 11:16:53 +0100
Subject: [PATCH] fix: ansible 2.12 and + compat + become fix

--- sshjail.py.orig	2021-08-15 18:02:16 UTC
+++ sshjail.py
@@ -289,6 +289,17 @@ DOCUMENTATION = '''
         vars:
           - name: ansible_ssh_use_tty
             version_added: '2.7'
+      pkcs11_provider:
+        version_added: '2.12'
+        default: ''
+        description:
+          - PKCS11 SmartCard provider such as opensc, example: /usr/local/lib/opensc-pkcs11.so
+          - Requires sshpass version 1.06+, sshpass must support the -P option.
+        env: [{name: ANSIBLE_PKCS11_PROVIDER}]
+        ini:
+          - {key: pkcs11_provider, section: ssh_connection}
+        vars:
+          - name: ansible_ssh_pkcs11_provider
       timeout:
         default: 10
         description:
@@ -420,6 +431,7 @@ class Connection(ConnectionBase):
         if 'sudo' in cmd:
             cmd = self._strip_sudo(executable, cmd)
 
+        self.set_option('host', self.host)
         cmd = ' '.join([executable, '-c', pipes.quote(cmd)])
         if slpcmd:
             cmd = '%s %s %s %s' % (self.get_jail_connector(), self.get_jail_id(), cmd, '&& sleep 0')
@@ -442,9 +454,11 @@ class Connection(ConnectionBase):
         return os.path.join(prefix, normpath[1:])
 
     def _copy_file(self, from_file, to_file, executable='/bin/sh'):
-        plugin = self.become
-        shell = get_shell_plugin(executable=executable)
-        copycmd = plugin.build_become_command(' '.join(['cp', from_file, to_file]), shell)
+        copycmd = ' '.join(['cp', from_file, to_file])
+        if self._play_context.become:
+        	plugin = self.become
+        	shell = get_shell_plugin(executable=executable)
+        	copycmd = plugin.build_become_command(copycmd, shell)
 
         display.vvv(u"REMOTE COPY {0} TO {1}".format(from_file, to_file), host=self.inventory_hostname)
         code, stdout, stderr = self._jailhost_command(copycmd)
