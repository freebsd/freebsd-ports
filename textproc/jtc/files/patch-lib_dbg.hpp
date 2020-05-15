--- lib/dbg.hpp.orig	2020-05-07 19:34:09 UTC
+++ lib/dbg.hpp
@@ -879,6 +879,9 @@ class __Dbg_flow__ {
                          }
                         }
 
+    static size_t       ind(void) { return __Dbg_flow__::ind_; }
+
+
  protected:
     const Debug &       dbg_;                                   // debug reference
     const char *        dfnc_;                                  // debug function
