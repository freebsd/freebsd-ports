--- src/gsl_fun.cpp.orig	2015-04-22 19:37:22 UTC
+++ src/gsl_fun.cpp
@@ -3183,7 +3183,7 @@ namespace lib {
       e->AssureScalarPar<DStringGDL>(0, tmpname);    
       name.reserve(tmpname.length());
       for (string::iterator it = tmpname.begin(); it < tmpname.end(); it++) 
-        if (*it != ' ' && *it != '_') name.append(1, (char)tolower(*it));
+        if (*it != ' ' && *it != '_') name.append(1, (char)std::tolower(*it));
     }
 
 #ifdef USE_UDUNITS
