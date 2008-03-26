--- lib/gibber/gibber-resolver.c.orig	2008-01-30 08:52:52.000000000 -0500
+++ lib/gibber/gibber-resolver.c	2008-03-25 22:58:24.000000000 -0400
@@ -720,7 +720,9 @@ gibber_resolver_gai_error_to_g_error (in
 
   switch (error) {
     case EAI_BADFLAGS:
+#ifdef EAI_ADDRFAMILY
     case EAI_ADDRFAMILY:
+#endif
     case EAI_SOCKTYPE:
     case EAI_FAMILY:
     case EAI_SERVICE:
@@ -731,13 +733,17 @@ gibber_resolver_gai_error_to_g_error (in
       code = GIBBER_RESOLVER_ERROR_RESOLVE_TEMPORARY_FAILURE;
       break;
     case EAI_FAIL:
+#ifdef EAI_NODATA
     case EAI_NODATA:
+#endif
     case EAI_NONAME:
       code = GIBBER_RESOLVER_ERROR_RESOLVE_FAILURE;
       break;
 
     case EAI_MEMORY:
+#ifdef EAI_OVERFLOW
     case EAI_OVERFLOW:
+#endif
       code = GIBBER_RESOLVER_ERROR_MEMORY;
       break;
 
