- from https://github.com/FreeFem/FreeFem-sources/issues/280#issuecomment-1596025016

--- plugin/seq/metis.cpp.orig	2023-06-18 09:28:12 UTC
+++ plugin/seq/metis.cpp
@@ -97,7 +97,7 @@ KN< R > *partmetis( KN< R > *const &part, FESPACE *con
       }
 
 #endif
-  } else epart = 0;
+  } else epart = static_cast<idx_t>(0);
   part->resize(nv);
   *part = npart;
   return part;
@@ -154,7 +154,7 @@ KN< R > *partmetis(Stack s, KN< R > *const &part, Mesh
       }
 
 #endif
-  } else epart = 0;
+  } else epart = static_cast<idx_t>(0);
   part->resize(nt);
   *part = epart;
   return part;
@@ -184,7 +184,7 @@ KN< long > *partmetisd(Stack s, KN< long > *const &par
       printf("  %d-way Edge-Cut: %7d, Balance: %5.2f\n", nparts, nve,
               ComputeElementBalance(nt, nparts, epart));
 #endif
-  } else epart = 0;
+  } else epart = static_cast<idx_t>(0);
   part->resize(nt);
   *part = epart;
   return part;
