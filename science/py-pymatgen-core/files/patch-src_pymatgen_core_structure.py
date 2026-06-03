--- src/pymatgen/core/structure.py.orig	2026-05-18 23:38:43 UTC
+++ src/pymatgen/core/structure.py
@@ -1182,7 +1182,7 @@ class IStructure(SiteCollection, MSONable):
                 )
                 new_sites.append(periodic_site)
 
-        new_charge = self._charge * np.linalg.det(scale_matrix) if self._charge else None
+        new_charge = self._charge * round(float(np.linalg.det(scale_matrix))) if self._charge else None
         return Structure.from_sites(new_sites, charge=new_charge, to_unit_cell=True).relabel_sites(ignore_uniq=True)
 
     def __rmul__(self, scaling_matrix):
