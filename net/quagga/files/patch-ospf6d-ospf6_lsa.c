--- ospf6d/ospf6_lsa.c	(revision 21)
+++ ospf6d/ospf6_lsa.c	(working copy)
@@ -207,9 +207,11 @@
     zlog_warn ("LSA: quagga_gettime failed, may fail LSA AGEs: %s",
                safe_strerror (errno));
 
-  if (lsa->header->age >= htons (MAXAGE))
+  if (ntohs (lsa->header->age) >= MAXAGE)
     {
-      /* LSA may have been prematurely aged */
+      /* ospf6_lsa_premature_aging () sets age to MAXAGE; when using
+         relative time, we cannot compare against lsa birth time, so
+         we catch this special case here. */
       lsa->header->age = htons (MAXAGE);
       return MAXAGE;
     }
@@ -245,11 +247,6 @@
   THREAD_OFF (lsa->expire);
   THREAD_OFF (lsa->refresh);
 
-  /* 
-   * The below technique to age out LSA does not work when using relative time 
-   *
-  memset (&lsa->birth, 0, sizeof (struct timeval));
-   */
   lsa->header->age = htons (MAXAGE);
   thread_execute (master, ospf6_lsa_expire, lsa, 0);
 }
