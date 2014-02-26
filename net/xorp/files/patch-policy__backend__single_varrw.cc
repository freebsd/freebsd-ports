--- ./policy/backend/single_varrw.cc.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./policy/backend/single_varrw.cc	2014-02-26 21:17:13.000000000 +0000
@@ -70,7 +70,11 @@
 
 	// out of luck...
 	if(!e)
-	    xorp_throw(SingleVarRWErr, "Unable to read variable " + id);
+	    // xorp_throw(SingleVarRWErr, "Unable to read variable " + id);
+	    { char *tmpstr;
+	      asprintf(&tmpstr, "Unable to read variable %d", id);
+	      xorp_throw(SingleVarRWErr, tmpstr);
+	    }
     }
 
     return *e;
