--- SoObjects/SOGo/LDAPSource.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/LDAPSource.m
@@ -1703,7 +1703,7 @@ _makeLDAPChanges (NGLdapConnection *ldap
                             hostname: hostname
                                 port: [NSString stringWithFormat: @"%d", port]
                           encryption: encryption
-                   bindAsCurrentUser: NO];
+                   bindAsCurrentUser: [NSString stringWithFormat: @"%d", NO]];
               [ab                     setBaseDN: [entry dn]
                                         IDField: @"cn"
                                         CNField: @"displayName"
