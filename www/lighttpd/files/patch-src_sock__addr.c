--- src/sock_addr.c.orig	2023-05-15 15:41:44 UTC
+++ src/sock_addr.c
@@ -496,7 +496,7 @@ int sock_addr_from_str_hints(sock_addr * const restric
             if (0 != (rc = getaddrinfo(str, NULL, &hints, &res))) {
                 hints.ai_family = AF_INET;
                 if (
-                  #ifdef EAI_ADDRFAMILY
+                  #if defined(__GLIBC__) && defined(EAI_ADDRFAMILY)
                     EAI_ADDRFAMILY == rc &&
                   #endif
                     0 == getaddrinfo(str, NULL, &hints, &res)) {
