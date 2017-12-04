--- plugins/provisioners/ansible/config/host.rb.orig	2017-11-12 01:10:25 UTC
+++ plugins/provisioners/ansible/config/host.rb
@@ -16,7 +16,7 @@ module VagrantPlugins
         #
         alias :ask_sudo_pass :ask_become_pass
         def ask_sudo_pass=(value)
-          show_deprecation_warning 'ask_sudo_pass', 'ask_become_pass'
+          show_deprecation_info 'ask_sudo_pass', 'ask_become_pass'
           @ask_become_pass = value
         end
 
