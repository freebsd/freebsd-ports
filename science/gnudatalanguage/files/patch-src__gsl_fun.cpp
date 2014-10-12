--- src/gsl_fun.cpp.orig	2014-10-09 22:55:52.000000000 +0200
+++ src/gsl_fun.cpp	2014-10-09 22:55:52.000000000 +0200
@@ -3183,7 +3183,7 @@
       e->AssureScalarPar<DStringGDL>(0, tmpname);    
       name.reserve(tmpname.length());
       for (string::iterator it = tmpname.begin(); it < tmpname.end(); it++) 
-        if (*it != ' ' && *it != '_') name.append(1, (char)tolower(*it));
+        if (*it != ' ' && *it != '_') name.append(1, (char)std::tolower(*it));
     }
 
 #ifdef USE_UDUNITS
