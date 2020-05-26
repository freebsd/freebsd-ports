--- shellinabox/service.c.orig
+++ shellinabox/service.c
@@ -175,8 +175,7 @@ void initService(struct Service *service, const char *
           "-oHostbasedAuthentication=no -oIdentitiesOnly=yes "
           "-oKbdInteractiveAuthentication=yes -oPasswordAuthentication=yes "
           "-oPreferredAuthentications=keyboard-interactive,password "
-          "-oPubkeyAuthentication=no -oRhostsRSAAuthentication=no "
-          "-oRSAAuthentication=no -oStrictHostKeyChecking=no -oTunnel=no "
+          "-oPubkeyAuthentication=no -oStrictHostKeyChecking=no -oTunnel=no "
           "-oUserKnownHostsFile=/dev/null -oVerifyHostKeyDNS=no "
 // beewoolie-2012.03.30: while it would be nice to disable this
 //          feature, we cannot be sure that it is available on the
