The trustlist feature, which only worked for a short period in 2003, was
removed in GpgME 2.0.0.

--- src/gpacontext.h.orig	2018-10-16 19:58:08 UTC
+++ src/gpacontext.h
@@ -63,7 +63,6 @@ struct _GpaContextClass {
   void (*start) (GpaContext *context);
   void (*done) (GpaContext *context, gpg_error_t err);
   void (*next_key) (GpaContext *context, gpgme_key_t key);
-  void (*next_trust_item) (GpaContext *context, gpgme_trust_item_t item);
   void (*progress) (GpaContext *context, int current, int total);
 };
 
