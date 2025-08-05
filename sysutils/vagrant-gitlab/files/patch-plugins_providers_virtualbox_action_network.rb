--- plugins/providers/virtualbox/action/network.rb.orig	2025-06-17 15:13:05 UTC
+++ plugins/providers/virtualbox/action/network.rb
@@ -21,7 +21,7 @@ module VagrantPlugins
       class Network
 
         # Location of the VirtualBox networks configuration file
-        VBOX_NET_CONF = "/etc/vbox/networks.conf".freeze
+        VBOX_NET_CONF = "@PREFIX@/etc/vbox/networks.conf".freeze
         # Version of VirtualBox that introduced hostonly network range restrictions
         HOSTONLY_VALIDATE_VERSION = Gem::Version.new("6.1.28")
         # Version of VirtualBox on darwin platform that ignores restrictions
