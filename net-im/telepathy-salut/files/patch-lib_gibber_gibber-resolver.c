--- lib/gibber/gibber-resolver.c.orig	2008-03-19 22:59:19.000000000 -0400
+++ lib/gibber/gibber-resolver.c	2008-03-19 23:00:18.000000000 -0400
@@ -720,7 +720,9 @@ gibber_resolver_gai_error_to_g_error (in
 
   switch (error) {
     case EAI_BADFLAGS:
+#ifdef EAI_ADDRFAMILY
     case EAI_ADDRFAMILY:
+#endif
     case EAI_SOCKTYPE:
     case EAI_FAMILY:
     case EAI_SERVICE:
@@ -731,7 +733,9 @@ gibber_resolver_gai_error_to_g_error (in
       code = GIBBER_RESOLVER_ERROR_RESOLVE_TEMPORARY_FAILURE;
       break;
     case EAI_FAIL:
+#ifdef EAI_NODATA
     case EAI_NODATA:
+#endif
     case EAI_NONAME:
       code = GIBBER_RESOLVER_ERROR_RESOLVE_FAILURE;
       break;
