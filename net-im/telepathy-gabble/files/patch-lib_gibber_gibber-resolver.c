--- lib/gibber/gibber-resolver.c.orig	2009-03-15 02:48:07.000000000 -0400
+++ lib/gibber/gibber-resolver.c	2009-03-15 02:48:53.000000000 -0400
@@ -735,7 +735,9 @@ gibber_resolver_gai_error_to_g_error (in
       break;
 
     case EAI_MEMORY:
+#ifdef EAI_OVERFLOW
     case EAI_OVERFLOW:
+#endif
       code = GIBBER_RESOLVER_ERROR_MEMORY;
       break;
 
