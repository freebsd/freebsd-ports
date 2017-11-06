--- plugins/communicators/ssh/communicator.rb.orig	2017-09-16 14:58:44 UTC
+++ plugins/communicators/ssh/communicator.rb
@@ -363,7 +363,7 @@
           forward_agent:         ssh_info[:forward_agent],
           send_env:              ssh_info[:forward_env],
           keys_only:             ssh_info[:keys_only],
-          paranoid:              ssh_info[:paranoid],
+          verify_host_key:       ssh_info[:paranoid],
           password:              ssh_info[:password],
           port:                  ssh_info[:port],
           timeout:               15,
