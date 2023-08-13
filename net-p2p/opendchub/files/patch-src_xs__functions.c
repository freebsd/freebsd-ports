--- src/xs_functions.c.orig	2014-08-14 15:04:19 UTC
+++ src/xs_functions.c
@@ -277,7 +277,10 @@ XS(xs_check_if_banned)
    if(ret != 1)
      ret = check_if_banned(user, NICKBAN);
    
-   (ret == 1) ? XSRETURN_IV(1) : XSRETURN_IV(0);
+   if (ret == 1)
+     XSRETURN_IV(1);
+   else
+     XSRETURN_IV(0);
 }
 
 XS(xs_check_if_allowed)
@@ -297,7 +300,10 @@ XS(xs_check_if_allowed)
    
    ret = check_if_allowed(user);
    
-   (ret == 1) ? XSRETURN_IV(1) : XSRETURN_IV(0);
+   if (ret == 1)
+     XSRETURN_IV(1);
+   else
+     XSRETURN_IV(0);
 }
 
 XS(xs_data_to_user)
