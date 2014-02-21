--- src/common/resolver.py.orig	2014-02-03 11:03:20.000000000 -0500
+++ src/common/resolver.py	2014-02-04 09:37:37.000000000 -0500
@@ -238,8 +238,8 @@
         return hosts
 
     def _parse_srv_result_posix(self, fqdn, result):
-        # typical output of bind-tools nslookup command:
-        # _xmpp-client._tcp.jabber.org    service = 30 30 5222 jabber.org.
+        # typical output of host lookup command
+        # _xmpp-client._tcp.jabber.org has SRV record 30 30 5222 jabber.org.
         if not result:
             return []
         ufqdn = helpers.ascii_to_idn(fqdn) # Unicode domain name
@@ -255,11 +255,12 @@
                 line = helpers.decode_string(line)
                 domain = ufqdn # For nslookup 9.6
             if domain:
-                rest = line[len(domain):].split('=')
+                # add 4 for ' has' after domain name
+                rest = line[len(domain)+4:].split('record')
                 if len(rest) != 2:
                     continue
                 answer_type, props_str = rest
-                if answer_type.strip() != 'service':
+                if answer_type.strip() != 'SRV':
                     continue
                 props = props_str.strip().split(' ')
                 if len(props) < 4:
@@ -309,7 +310,7 @@
             return
 
     def _compose_command_args(self):
-        return ['nslookup', '-type=' + self.type, self.host]
+        return ['host', '-t', self.type, self.host]
 
     def _return_result(self):
         if self.result_handler:
