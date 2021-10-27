--- shellinabox/service.c.orig	2016-11-09 19:40:33 UTC
+++ shellinabox/service.c
@@ -169,14 +169,13 @@ void initService(struct Service *service, const char *
     }
 
     service->cmdline                        = stringPrintf(NULL,
-      "ssh -a -e none -i /dev/null -x -oChallengeResponseAuthentication=no "
+      "ssh -a -e none -i /dev/null -x "
           "-oCheckHostIP=no -oClearAllForwardings=yes -oCompression=no "
-          "-oControlMaster=no -oGSSAPIAuthentication=no "
+          "-oControlMaster=no "
           "-oHostbasedAuthentication=no -oIdentitiesOnly=yes "
           "-oKbdInteractiveAuthentication=yes -oPasswordAuthentication=yes "
           "-oPreferredAuthentications=keyboard-interactive,password "
-          "-oPubkeyAuthentication=no -oRhostsRSAAuthentication=no "
-          "-oRSAAuthentication=no -oStrictHostKeyChecking=no -oTunnel=no "
+          "-oPubkeyAuthentication=no -oStrictHostKeyChecking=no -oTunnel=no "
           "-oUserKnownHostsFile=/dev/null -oVerifyHostKeyDNS=no "
 // beewoolie-2012.03.30: while it would be nice to disable this
 //          feature, we cannot be sure that it is available on the
