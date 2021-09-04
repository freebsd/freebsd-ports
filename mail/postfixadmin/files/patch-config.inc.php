--- config.inc.php.orig	2021-08-09 14:34:09 UTC
+++ config.inc.php
@@ -212,10 +212,11 @@ $CONF['authlib_default_flavor'] = 'md5raw';
 // for dovecot 1.x
 // $CONF['dovecotpw'] = "/usr/sbin/dovecotpw";
 // for dovecot 2.x (dovecot 2.0.0 - 2.0.7 is not supported!)
-$CONF['dovecotpw'] = "/usr/sbin/doveadm pw";
-if(@file_exists('/usr/bin/doveadm')) { // @ to silence openbase_dir stuff; see https://github.com/postfixadmin/postfixadmin/issues/171
-    $CONF['dovecotpw'] = "/usr/bin/doveadm pw"; # debian
-}
+#$CONF['dovecotpw'] = "/usr/sbin/doveadm pw";
+#if(@file_exists('/usr/bin/doveadm')) { // @ to silence openbase_dir stuff; see https://github.com/postfixadmin/postfixadmin/issues/171
+#    $CONF['dovecotpw'] = "/usr/bin/doveadm pw"; # debian
+#}
+$CONF['dovecotpw'] = "/usr/local/sbin/dovecotpw"; # FreeBSD
 
 // Password validation
 // New/changed passwords will be validated using all regular expressions in the array.
