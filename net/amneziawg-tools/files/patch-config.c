--- config.c.orig	2025-06-13 09:33:11 UTC
+++ config.c
@@ -252,7 +252,7 @@ static inline bool parse_endpoint(struct sockaddr *end
 		 *
 		 * So this is what we do, except FreeBSD removed EAI_NODATA some time ago, so that's conditional.
 		 */
-		if (ret == EAI_NONAME || ret == EAI_FAIL ||
+		if (/* ret == EAI_NONAME || */ ret == EAI_FAIL ||
 			#ifdef EAI_NODATA
 				ret == EAI_NODATA ||
 			#endif
