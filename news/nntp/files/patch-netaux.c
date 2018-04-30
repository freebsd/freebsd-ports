--- server/netaux.c.orig	2018-04-30 06:13:43 UTC
+++ server/netaux.c
@@ -281,10 +281,4 @@ reaper(int unused)
 
 #else /* !ALONE */
 
-/* Kludge for greenhill's C compiler */
-
-static
-netaux_greenkludge()
-{
-}
 #endif /* not ALONE */
