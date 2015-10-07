--- policy/backend/single_varrw.cc.orig	2012-01-11 17:56:10 UTC
+++ policy/backend/single_varrw.cc
@@ -70,7 +70,11 @@ SingleVarRW::read(const Id& id)
 
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
