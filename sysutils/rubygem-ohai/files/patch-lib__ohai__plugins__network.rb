--- lib/ohai/plugins/network.rb.orig	2013-10-28 22:14:54.275284113 +0000
+++ lib/ohai/plugins/network.rb	2013-10-28 22:15:30.024281591 +0000
@@ -39,6 +39,7 @@
   # going to use that later to sort by scope
   scope_prio = [ "global", "site", "link", "host", "node", nil ]
 
+      next if iface_v.nil? or not iface_v.has_key? 'addresses'
   ipaddresses = []
   # ipaddresses going to hold #{family} ipaddresses and their scope
   Mash[network['interfaces']].each do |iface, iface_v|
