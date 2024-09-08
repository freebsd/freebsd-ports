--- sieve/interp.c.orig	2023-12-01 06:24:31 UTC
+++ sieve/interp.c
@@ -749,11 +749,13 @@ unsigned long long extension_isactive(sieve_interp_t *
               (config_ext & IMAP_ENUM_SIEVE_EXTENSIONS_VND_CYRUS_LOG))) capa = 0;
         break;
 
+#ifdef WITH_JMAP
     case SIEVE_CAPA_JMAPQUERY:
         if (!(interp->jmapquery &&
               (config_ext & IMAP_ENUM_SIEVE_EXTENSIONS_VND_CYRUS_JMAPQUERY)))
             capa = 0;
         break;
+#endif
 
     case SIEVE_CAPA_SNOOZE:
         if (!(interp->snooze &&
