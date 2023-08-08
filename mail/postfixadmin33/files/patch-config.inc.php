--- config.inc.php.orig	2022-12-08 20:34:43 UTC
+++ config.inc.php
@@ -214,10 +214,11 @@ $CONF['authlib_default_flavor'] = 'md5raw';
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
