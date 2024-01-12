--- librepo/gpg_gpgme.c.orig	2024-01-12 02:28:14 UTC
+++ librepo/gpg_gpgme.c
@@ -144,6 +144,7 @@ exit:
     }
     freecon(old_default_context);
 #endif
+    return; // w/out this there's error only on i386: librepo/gpg_gpgme.c:147:1: error: expected statement
 }
 
 static gpgme_ctx_t
