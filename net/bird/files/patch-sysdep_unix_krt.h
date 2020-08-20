--- sysdep/unix/krt.h.orig	2020-08-20 21:22:44 UTC
+++ sysdep/unix/krt.h
@@ -112,7 +112,7 @@ struct kif_proto {
   struct kif_state sys;		/* Sysdep state */
 };
 
-struct kif_proto *kif_proto;
+extern struct kif_proto *kif_proto;
 
 #define KIF_CF ((struct kif_config *)p->p.cf)
 
