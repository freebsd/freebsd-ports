--- ./nslcd/nslcd.c.orig	2009-06-12 21:53:18.000000000 +0000
+++ ./nslcd/nslcd.c	2009-08-02 22:32:27.000000000 +0000
@@ -398,9 +398,9 @@
     case NSLCD_ACTION_NETWORK_BYNAME:   (void)nslcd_network_byname(fp,session); break;
     case NSLCD_ACTION_NETWORK_BYADDR:   (void)nslcd_network_byaddr(fp,session); break;
     case NSLCD_ACTION_NETWORK_ALL:      (void)nslcd_network_all(fp,session); break;
-    case NSLCD_ACTION_PASSWD_BYNAME:    (void)nslcd_passwd_byname(fp,session); break;
-    case NSLCD_ACTION_PASSWD_BYUID:     (void)nslcd_passwd_byuid(fp,session); break;
-    case NSLCD_ACTION_PASSWD_ALL:       (void)nslcd_passwd_all(fp,session); break;
+    case NSLCD_ACTION_PASSWD_BYNAME:    (void)nslcd_passwd_byname(fp,session,uid); break;
+    case NSLCD_ACTION_PASSWD_BYUID:     (void)nslcd_passwd_byuid(fp,session,uid); break;
+    case NSLCD_ACTION_PASSWD_ALL:       (void)nslcd_passwd_all(fp,session,uid); break;
     case NSLCD_ACTION_PROTOCOL_BYNAME:  (void)nslcd_protocol_byname(fp,session); break;
     case NSLCD_ACTION_PROTOCOL_BYNUMBER:(void)nslcd_protocol_bynumber(fp,session); break;
     case NSLCD_ACTION_PROTOCOL_ALL:     (void)nslcd_protocol_all(fp,session); break;
