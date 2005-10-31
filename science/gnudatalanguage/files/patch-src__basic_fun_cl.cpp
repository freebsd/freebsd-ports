--- src/basic_fun_cl.cpp.orig	Mon Oct 17 10:22:04 2005
+++ src/basic_fun_cl.cpp	Sun Oct 23 15:32:34 2005
@@ -131,7 +131,7 @@
       }
     }
 
-    //return the variable in seconds, either JULIAN, JULIAN+UTC, 
+    //return the variable in seconds, either JULIAN, JULIAN+UTC,
     //or no other keywords
     struct tm *tstruct;
     if( ret_seconds || e->KeywordSet("SECONDS") )
@@ -139,38 +139,38 @@
        if( e->KeywordSet("JULIAN") )
          {
            if( e->KeywordSet("UTC") )
-             tstruct=gmtime(&tval.tv_sec);
+             tstruct=gmtime((time_t *)(&tval.tv_sec));
            else
-             tstruct=localtime(&tval.tv_sec);
-         
+             tstruct=localtime((time_t *)(&tval.tv_sec));
+
            return new DDoubleGDL(Gregorian2Julian(tstruct));
          }
-       else 
+       else
          {
            // does not (necessaryly) work: time might count backwards
            //double tickTime = static_cast<double>(t) + tt - floor( tt);
            return new DDoubleGDL(static_cast<double>(tt));
          }
       }
-    
+
     //return a string of the time, either UTC or local (default)
     if(e->KeywordSet("UTC"))
-      tstruct= gmtime(&tval.tv_sec);
+      tstruct= gmtime((time_t *)(&tval.tv_sec));
     else
-      tstruct= localtime(&tval.tv_sec);
-    
+      tstruct= localtime((time_t *)(&tval.tv_sec));
+
     //Convert the time to JULIAN or NOT
     if(e->KeywordSet("JULIAN"))
-        return new DDoubleGDL(Gregorian2Julian(tstruct)); 
-    else 
+        return new DDoubleGDL(Gregorian2Julian(tstruct));
+    else
       {
        char *st=new char[MAX_DATE_STRING_LENGTH];
        const char *format="%a %h %d %T %Y";//my IDL date format.
        DStringGDL *S;
-                 
+
        SizeT res=strftime(st,MAX_DATE_STRING_LENGTH,format,tstruct);
 
-       if(res != 0) 
+       if(res != 0)
          S=new DStringGDL(st);
        else
          S=new DStringGDL("");
