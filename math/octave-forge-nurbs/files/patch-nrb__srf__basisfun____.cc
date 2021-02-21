--- nrb_srf_basisfun__.cc.orig	2021-02-21 22:34:12 UTC
+++ nrb_srf_basisfun__.cc
@@ -66,7 +66,7 @@ DEFUN_DLD(nrb_srf_basisfun__, args, nargout,"\
 	} // spu  =  findspan (m, p, u, U); 
 
       newargs(3) = U; newargs(2) = p; newargs(1) = u; newargs(0) = spu;
-      Matrix Ik = feval (std::string("numbasisfun"), newargs, 1)(0).matrix_value (); // Ik = numbasisfun (spu, u, p, U);
+      Matrix Ik = octave::feval (std::string("numbasisfun"), newargs, 1)(0).matrix_value (); // Ik = numbasisfun (spu, u, p, U);
 
       RowVector spv(v);
       for (octave_idx_type ii(0); ii < v.numel (); ii++)
@@ -75,7 +75,7 @@ DEFUN_DLD(nrb_srf_basisfun__, args, nargout,"\
 	} // spv  =  findspan (n, q, v, V);
 
       newargs(3) = V; newargs(2) = q; newargs(1) = v; newargs(0) = spv;
-      Matrix Jk = feval (std::string("numbasisfun"), newargs, 1)(0).matrix_value (); // Jk = numbasisfun (spv, v, q, V);
+      Matrix Jk = octave::feval (std::string("numbasisfun"), newargs, 1)(0).matrix_value (); // Jk = numbasisfun (spv, v, q, V);
 
       Matrix NuIkuk(npt, p+1, 0.0);
       for (octave_idx_type ii(0); ii < npt; ii++)
