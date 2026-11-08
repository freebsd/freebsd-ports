From ed8a73bae935f851111241e34338bcc708888ad4 Mon Sep 17 00:00:00 2001
From: Geoffroy Desvernay <dgeo@centrale-med.fr>
Date: Sun, 15 Feb 2026 15:28:19 +0100
Subject: [PATCH] add missing parameters definitions

Fix errors with ansible 2.19

should fix #45
--- sshjail.py.orig	2025-01-20 16:31:12 UTC
+++ sshjail.py
@@ -8,7 +8,7 @@ from ansible.plugins.connection.ssh import Connection 
 from ansible import __version__ as ansible_version
 from ansible.errors import AnsibleError
 from ansible.plugins.connection.ssh import Connection as SSHConnection
-from ansible.module_utils._text import to_text
+from ansible.module_utils.common.text.converters import to_text
 from ansible.plugins.loader import get_shell_plugin
 from contextlib import contextmanager
 
@@ -16,6 +16,10 @@ MIN_ANSIBLE_VERSION = '2.11.3'
 
 MIN_ANSIBLE_VERSION = '2.11.3'
 
+# become commands that must be stripped before running inside the jail,
+# as the jail itself usually has neither installed
+BECOME_EXES = ('sudo', 'doas')
+
 DOCUMENTATION = '''
     connection: sshjail
     short_description: connect via ssh client binary to jail
@@ -54,6 +58,21 @@ DOCUMENTATION = '''
           vars:
               - name: ansible_password
               - name: ansible_ssh_pass
+      password_mechanism:
+          description: Mechanism to use for handling ssh password prompt
+          type: string
+          default: ssh_askpass
+          choices:
+              - ssh_askpass
+              - sshpass
+              - disable
+          version_added: '2.19'
+          env:
+              - name: ANSIBLE_SSH_PASSWORD_MECHANISM
+          ini:
+              - {key: password_mechanism, section: ssh_connection}
+          vars:
+              - name: ansible_ssh_password_mechanism
       sshpass_prompt:
           description: Password prompt that sshpass should search for. Supported by sshpass 1.06 and up
           default: ''
@@ -225,7 +244,30 @@ DOCUMENTATION = '''
           vars:
             - name: ansible_private_key_file
             - name: ansible_ssh_private_key_file
-
+          cli:
+            - name: private_key_file
+              option: --private-key
+      private_key:
+          description:
+            - Private key contents in PEM format. Requires the C(SSH_AGENT) configuration to be enabled.
+          type: string
+          env:
+            - name: ANSIBLE_PRIVATE_KEY
+          vars:
+            - name: ansible_private_key
+            - name: ansible_ssh_private_key
+          version_added: '2.19'
+      private_key_passphrase:
+          description:
+            - Private key passphrase, dependent on O(private_key).
+            - This does NOT have any effect when used with O(private_key_file).
+          type: string
+          env:
+            - name: ANSIBLE_PRIVATE_KEY_PASSPHRASE
+          vars:
+            - name: ansible_private_key_passphrase
+            - name: ansible_ssh_private_key_passphrase
+          version_added: '2.19'
       control_path:
         description:
           - This is the location to save ssh's ControlPath sockets, it uses ssh's variable substitution.
@@ -302,7 +344,6 @@ DOCUMENTATION = '''
         default: ''
         description:
           - PKCS11 SmartCard provider such as opensc, example: /usr/local/lib/opensc-pkcs11.so
-          - Requires sshpass version 1.06+, sshpass must support the -P option.
         env: [{name: ANSIBLE_PKCS11_PROVIDER}]
         ini:
           - {key: pkcs11_provider, section: ssh_connection}
@@ -329,6 +370,17 @@ DOCUMENTATION = '''
         cli:
             - name: timeout
         type: integer
+      verbosity:
+        version_added: '2.19'
+        default: 0
+        type: int
+        description:
+          - Requested verbosity level for the SSH CLI.
+        env: [{name: ANSIBLE_SSH_VERBOSITY}]
+        ini:
+          - {key: verbosity, section: ssh_connection}
+        vars:
+          - name: ansible_ssh_verbosity
 '''
 
 try:
@@ -422,7 +474,7 @@ class Connection(ConnectionBase):
 
         # to do this, we peel back successive command invocations
         words = shlex.split(cmd)
-        while words[0] == executable or words[0] == 'sudo':
+        while words[0] == executable or words[0] in BECOME_EXES:
             cmd = words[-1]
             words = shlex.split(cmd)
 
@@ -454,7 +506,7 @@ class Connection(ConnectionBase):
             slpcmd = True
             cmd = self._strip_sleep(cmd)
 
-        if 'sudo' in cmd:
+        if any(exe in cmd for exe in BECOME_EXES):
             cmd = self._strip_sudo(executable, cmd)
 
         self.set_option('host', self.host)
