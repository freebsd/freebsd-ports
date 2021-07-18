From bcb0a961df77a0d7a3b2e7e58fac3e283b5ef8c4 Mon Sep 17 00:00:00 2001
From: Mohamad Safadieh <self@mhmd.sh>
Date: Wed, 5 May 2021 12:38:26 -0400
Subject: [PATCH] added sshpass_prompt, ssh_transfer_method, timeout

---
 sshjail.py | 42 ++++++++++++++++++++++++++++++++++++++++++
 1 file changed, 42 insertions(+)

diff --git a/sshjail.py b/sshjail.py
index 5973380..0e26c68 100644
--- sshjail.py
+++ sshjail.py
@@ -49,6 +49,17 @@
           vars:
               - name: ansible_password
               - name: ansible_ssh_pass
+      sshpass_prompt:
+          description: Password prompt that sshpass should search for. Supported by sshpass 1.06 and up
+          default: ''
+          ini:
+              - section: 'ssh_connection'
+                key: 'sshpass_prompt'
+          env:
+              - name: ANSIBLE_SSHPASS_PROMPT
+          vars:
+              - name: ansible_sshpass_prompt
+          version_added: '2.10'
       ssh_args:
           description: Arguments to pass to all ssh cli tools
           default: '-C -o ControlMaster=auto -o ControlPersist=60s'
@@ -247,6 +258,16 @@
         vars:
           - name: ansible_sftp_batch_mode
             version_added: '2.7'
+      ssh_transfer_method:
+        default: smart
+        description:
+            - "Preferred method to use when transferring files over ssh"
+            - Setting to 'smart' (default) will try them in order, until one succeeds or they all fail
+            - Using 'piped' creates an ssh pipe with ``dd`` on either side to copy the data
+        choices: ['sftp', 'scp', 'piped', 'smart']
+        env: [{name: ANSIBLE_SSH_TRANSFER_METHOD}]
+        ini:
+            - {key: transfer_method, section: ssh_connection}
       scp_if_ssh:
         default: smart
         description:
@@ -270,6 +291,27 @@
         vars:
           - name: ansible_ssh_use_tty
             version_added: '2.7'
+      timeout:
+        default: 10
+        description:
+            - This is the default ammount of time we will wait while establishing an ssh connection
+            - It also controls how long we can wait to access reading the connection once established (select on the socket)
+        env:
+            - name: ANSIBLE_TIMEOUT
+            - name: ANSIBLE_SSH_TIMEOUT
+              version_added: '2.11'
+        ini:
+            - key: timeout
+              section: defaults
+            - key: timeout
+              section: ssh_connection
+              version_added: '2.11'
+        vars:
+            - name: ansible_ssh_timeout
+              version_added: '2.11'
+        cli:
+            - name: timeout
+        type: integer
 '''
 
 try:
