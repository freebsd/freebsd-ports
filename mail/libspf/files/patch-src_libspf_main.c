--- src/libspf/main.c.orig Thu Jul 28 17:23:42 2005
+++ src/libspf/main.c      Thu Jul 28 17:24:11 2005
@@ -1683,7 +1683,7 @@
     xfree(p->from);
   }

-  if (p->spf_rlevel > 0)
+  if (p->spf_rlevel > 0 && p->current_domain != p->original_domain)
   {
     xfree(p->current_domain);
   }
