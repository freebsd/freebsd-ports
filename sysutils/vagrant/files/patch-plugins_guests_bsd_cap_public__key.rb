--- plugins/guests/bsd/cap/public_key.rb.orig	2016-09-16 14:28:57 UTC
+++ plugins/guests/bsd/cap/public_key.rb
@@ -54,6 +54,7 @@ module VagrantPlugins
             if test -f ~/.ssh/authorized_keys; then
               grep -v -x -f '#{remote_path}' ~/.ssh/authorized_keys > ~/.ssh/authorized_keys.tmp
               mv ~/.ssh/authorized_keys.tmp ~/.ssh/authorized_keys
+              chmod 0600 ~/.ssh/authorized_keys
             fi
 
             rm -f '#{remote_path}'
