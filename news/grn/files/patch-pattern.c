--- libmutt/pattern.c.orig	Tue Aug 17 16:08:15 2004
+++ libmutt/pattern.c	Tue Aug 17 16:09:00 2004
@@ -883,6 +883,7 @@
      return (pat->not ^ (h->pgp & PGPKEY));
 #endif
 #endif
+     break;
   }
   mutt_error ("error: unknown op %d (report this error).", pat->op);
   return (-1);
