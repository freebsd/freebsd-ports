--- lily/include/smobs.hh.orig	2024-07-20 11:21:13 UTC
+++ lily/include/smobs.hh
@@ -244,6 +244,7 @@ class Smob_base (private)
 #define LY_DECLARE_SMOB_PROC(PMF, REQ, OPT, VAR)                               \
   LY_DECLARE_STATIC_SMOB_PROC (smob_trampoline<PMF>, REQ, OPT, VAR)
 
+protected:
   // Template parameter packs could reduce repetition here; however,
   // they would allow parameter types other than SCM.  It turns out
   // that GUILE 1.8.8 cannot actually make callable structures with
@@ -272,6 +273,7 @@ class Smob_base (private)
     return (Super::unchecked_unsmob (self)->*pmf) (arg1, arg2, arg3);
   }
 
+private:
   static bool is_smob (SCM s)
   {
     return SCM_SMOB_PREDICATE (smob_tag (), s);
