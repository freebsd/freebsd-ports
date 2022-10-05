--- plugins/providers/virtualbox/action/network.rb.orig	2021-11-05 21:15:44 UTC
+++ plugins/providers/virtualbox/action/network.rb
@@ -18,7 +18,7 @@ module VagrantPlugins
       class Network
 
         # Location of the VirtualBox networks configuration file
-        VBOX_NET_CONF = "/etc/vbox/networks.conf".freeze
+        VBOX_NET_CONF = "@PREFIX@/etc/vbox/networks.conf".freeze
         # Version of VirtualBox that introduced hostonly network range restrictions
         HOSTONLY_VALIDATE_VERSION = Gem::Version.new("6.1.28")
         # Default valid range for hostonly networks
