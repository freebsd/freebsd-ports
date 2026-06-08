--- lib/gssapi/krb5/import_name.c.orig	2026-06-08 07:48:11.489573000 -0700
+++ lib/gssapi/krb5/import_name.c	2026-06-08 07:49:18.639094000 -0700
@@ -302,7 +302,8 @@
                     goto fail_name;
                 cp += length;
             }
-            assert(cp == end);
+            if (cp != end)
+		goto fail_name;
         } else {
             status = GSS_S_BAD_NAMETYPE;
             goto cleanup;
