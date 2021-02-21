--- nrb_srf_basisfun_der__.cc.orig	2021-02-21 22:32:34 UTC
+++ nrb_srf_basisfun_der__.cc
@@ -73,7 +73,7 @@ DEFUN_DLD(nrb_srf_basisfun_der__, args, nargout,"\
 	} // spu  =  findspan (m, p, u, U); 
 
       newargs(3) = U; newargs(2) = p; newargs(1) = u; newargs(0) = spu;
-      Matrix Ik = feval (std::string("numbasisfun"), newargs, 1)(0).matrix_value (); // Ik = numbasisfun (spu, u, p, U);
+      Matrix Ik = octave::feval (std::string("numbasisfun"), newargs, 1)(0).matrix_value (); // Ik = numbasisfun (spu, u, p, U);
 
       RowVector spv(v);
       for (octave_idx_type ii(0); ii < v.numel (); ii++)
@@ -82,7 +82,7 @@ DEFUN_DLD(nrb_srf_basisfun_der__, args, nargout,"\
 	} // spv  =  findspan (n, q, v, V);
 
       newargs(3) = V; newargs(2) = q; newargs(1) = v; newargs(0) = spv;
-      Matrix Jk = feval (std::string("numbasisfun"), newargs, 1)(0).matrix_value (); // Jk = numbasisfun (spv, v, q, V);
+      Matrix Jk = octave::feval (std::string("numbasisfun"), newargs, 1)(0).matrix_value (); // Jk = numbasisfun (spv, v, q, V);
 
       Matrix NuIkuk(npt, p+1, 0.0);
       for (octave_idx_type ii(0); ii < npt; ii++)
@@ -100,11 +100,11 @@ DEFUN_DLD(nrb_srf_basisfun_der__, args, nargout,"\
 
      
       newargs(4) = 1; newargs(3) = U; newargs(2) = u; newargs(1) = p; newargs(0) = spu;
-      NDArray NuIkukprime = feval (std::string("basisfunder"), newargs, 1)(0).array_value (); //   NuIkukprime = basisfunder (spu, p, u, U, 1);
+      NDArray NuIkukprime = octave::feval (std::string("basisfunder"), newargs, 1)(0).array_value (); //   NuIkukprime = basisfunder (spu, p, u, U, 1);
                                                                                               //   NuIkukprime = squeeze(NuJkukprime(:,2,:));
       
       newargs(4) = 1; newargs(3) = V; newargs(2) = v; newargs(1) = q; newargs(0) = spv;
-      NDArray NvJkvkprime = feval (std::string("basisfunder"), newargs, 1)(0).array_value (); //   NvJkvkprime = basisfunder (spv, q, v, V, 1);
+      NDArray NvJkvkprime = octave::feval (std::string("basisfunder"), newargs, 1)(0).array_value (); //   NvJkvkprime = basisfunder (spv, q, v, V, 1);
                                                                                               //   NvJkvkprime = squeeze(NvJkvkprime(:,2,:));
       
       for (octave_idx_type k(0); k < npt; k++) 
