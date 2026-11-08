-- Fix non-OpenMP serial build: use shells_[i].center_ind() instead of the
-- non-existent shells[i].get_center_ind() in the #else branches.

--- src/basis.cpp.orig	2026-09-30 19:12:51 UTC
+++ src/basis.cpp
@@ -2550,8 +2550,8 @@ arma::vec BasisSet::nuclear_pulay(const arma::mat & P)
 	fwrk.subvec(3*shells_[i].center_ind(),3*shells_[i].center_ind()+2)+=tmp.subvec(0,2);
 	fwrk.subvec(3*shells_[j].center_ind(),3*shells_[j].center_ind()+2)+=tmp.subvec(3,5);
 #else
-	f.subvec(3*shells[i].get_center_ind(),3*shells[i].get_center_ind()+2)+=tmp.subvec(0,2);
-	f.subvec(3*shells[j].get_center_ind(),3*shells[j].get_center_ind()+2)+=tmp.subvec(3,5);
+	f.subvec(3*shells_[i].center_ind(),3*shells_[i].center_ind()+2)+=tmp.subvec(0,2);
+	f.subvec(3*shells_[j].center_ind(),3*shells_[j].center_ind()+2)+=tmp.subvec(3,5);
 #endif
       }
 
@@ -2666,8 +2666,8 @@ arma::vec BasisSet::kinetic_pulay(const arma::mat & P)
       fwrk.subvec(3*shells_[i].center_ind(),3*shells_[i].center_ind()+2)+=tmp.subvec(0,2);
       fwrk.subvec(3*shells_[j].center_ind(),3*shells_[j].center_ind()+2)+=tmp.subvec(3,5);
 #else
-      f.subvec(3*shells[i].get_center_ind(),3*shells[i].get_center_ind()+2)+=tmp.subvec(0,2);
-      f.subvec(3*shells[j].get_center_ind(),3*shells[j].get_center_ind()+2)+=tmp.subvec(3,5);
+      f.subvec(3*shells_[i].center_ind(),3*shells_[i].center_ind()+2)+=tmp.subvec(0,2);
+      f.subvec(3*shells_[j].center_ind(),3*shells_[j].center_ind()+2)+=tmp.subvec(3,5);
 #endif
     }
 
@@ -2719,8 +2719,8 @@ arma::vec BasisSet::overlap_der(const arma::mat & P) c
       fwrk.subvec(3*shells_[i].center_ind(),3*shells_[i].center_ind()+2)+=tmp.subvec(0,2);
       fwrk.subvec(3*shells_[j].center_ind(),3*shells_[j].center_ind()+2)+=tmp.subvec(3,5);
 #else
-      f.subvec(3*shells[i].get_center_ind(),3*shells[i].get_center_ind()+2)+=tmp.subvec(0,2);
-      f.subvec(3*shells[j].get_center_ind(),3*shells[j].get_center_ind()+2)+=tmp.subvec(3,5);
+      f.subvec(3*shells_[i].center_ind(),3*shells_[i].center_ind()+2)+=tmp.subvec(0,2);
+      f.subvec(3*shells_[j].center_ind(),3*shells_[j].center_ind()+2)+=tmp.subvec(3,5);
 #endif
     }
 
