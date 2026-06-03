From ed8a73bae935f851111241e34338bcc708888ad4 Mon Sep 17 00:00:00 2001
From: Geoffroy Desvernay <dgeo@centrale-med.fr>
Date: Sun, 15 Feb 2026 15:28:19 +0100
Subject: [PATCH] add missing parameters definitions

Fix errors with ansible 2.19

should fix #45
---
 sshjail.py | 52 ++++++++++++++++++++++++++++++++++++++++++++++++++--
 1 file changed, 50 insertions(+), 2 deletions(-)

diff --git a/sshjail.py b/sshjail.py
index 3938a5c..b16a9cc 100644
--- sshjail.py
+++ sshjail.py
@@ -54,6 +54,21 @@
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
@@ -225,7 +240,30 @@
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
@@ -302,7 +340,6 @@
         default: ''
         description:
           - PKCS11 SmartCard provider such as opensc, example: /usr/local/lib/opensc-pkcs11.so
-          - Requires sshpass version 1.06+, sshpass must support the -P option.
         env: [{name: ANSIBLE_PKCS11_PROVIDER}]
         ini:
           - {key: pkcs11_provider, section: ssh_connection}
@@ -329,6 +366,17 @@
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
