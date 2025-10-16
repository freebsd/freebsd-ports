--- epan/dissectors/packet-kerberos.c.orig	2025-10-16 15:54:37 UTC
+++ epan/dissectors/packet-kerberos.c
@@ -3401,7 +3401,7 @@ read_keytab_file(const char *filename)
 
 			/* generate origin string, describing where this key came from */
 			for(i=0;i<key.principal->name.name_string.len;i++){
-				wmem_strbuf_append_printf(str_principal, "%s%s",(i?"/":""),key.principal->name.name_string.val[i]));
+				wmem_strbuf_append_printf(str_principal, "%s%s",(i?"/":""),key.principal->name.name_string.val[i]);
 			}
 			wmem_strbuf_append_printf(str_principal, "@%s",key.principal->realm);
 			new_key->key_origin = (char*)wmem_strbuf_get_str(str_principal);
