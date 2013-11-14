--- lib/ohai/plugins/network.rb.orig    2013-10-30 11:59:28.417251343 +0100
+++ lib/ohai/plugins/network.rb 2013-10-30 11:59:24.993251926 +0100
@@ -42,6 +42,7 @@
   ipaddresses = []
   # ipaddresses going to hold #{family} ipaddresses and their scope
   Mash[network['interfaces']].each do |iface, iface_v|
+    next if iface_v.nil? or not iface_v.has_key? 'addresses'
     iface_v['addresses'].each do |addr, addr_v|
       next if addr_v.nil? or not addr_v.has_key? "family" or addr_v['family'] != family
       ipaddresses <<  {

