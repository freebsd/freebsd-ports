--- cf/m4/cfhead.m4.orig	2020-05-19 19:54:31 UTC
+++ cf/m4/cfhead.m4
@@ -278,7 +278,8 @@ define(`_REC_AUTH_', `$.$?{auth_type}(authenticated')
 define(`_REC_FULL_AUTH_', `$.$?{auth_type}(user=${auth_authen} $?{auth_author}author=${auth_author} $.mech=${auth_type}')
 define(`_REC_HDR_', `$?sfrom $s $.$?_($?s$|from $.$_)')
 define(`_REC_END_', `for $u; $|;
-	$.$b')
+	$.$b$?g
+	(envelope-from $g)$.')
 define(`_REC_TLS_', `(version=${tls_version} cipher=${cipher} bits=${cipher_bits} verify=${verify})$.$?u')
 define(`_REC_BY_', `$.by $j ($v/$Z)$?r with $r$. id $i$?{tls_version}')
 define(`confRECEIVED_HEADER', `_REC_HDR_
