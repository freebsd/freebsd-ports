--- ./src/gsl_fun.cpp.orig	2014-04-08 16:53:53.901118160 +0200
+++ ./src/gsl_fun.cpp	2014-04-08 16:53:54.111117458 +0200
@@ -3378,7 +3378,7 @@
       e->AssureScalarPar<DStringGDL>(0, tmpname);    
       name.reserve(tmpname.length());
       for (string::iterator it = tmpname.begin(); it < tmpname.end(); it++) 
-        if (*it != ' ' && *it != '_') name.append(1, (char)tolower(*it));
+        if (*it != ' ' && *it != '_') name.append(1, (char)std::tolower(*it));
     }
 
 #ifdef USE_UDUNITS
@@ -3889,7 +3889,7 @@
 	  res[j] = sign * sphPlm.val;
 	*/
 	res[j] = sign * gsl_sf_legendre_sphPlm(l, abs(m), cos(theta[j * step_theta]));
-	res[j] *= exp(complex<T_phi>(0., m * phi[j * step_phi]));
+	res[j] *= T_res(std::exp(complex<T_phi>(0., m * phi[j * step_phi])));
       }
   }
   template <class T_phi, class T_res>
