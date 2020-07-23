--- lib/App/Acmeman/Source/Default.pm.orig	2020-01-14 19:47:02 UTC
+++ lib/App/Acmeman/Source/Default.pm
@@ -27,8 +27,8 @@ The source module couldn't be loaded because of the fo
 "$s"    
     
 If you are going to use the "apache" source, fix this error and retry.
-Otherwise, please create the /etc/acmeman.conf configuration file, and
-configure another domain source, for example:
+Otherwise, please create the /etc/acmeman.conf configuration
+file, and configure another domain source, for example:
 
     [core]
 	source = file DOMAINFILE
