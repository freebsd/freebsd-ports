--- src/scd_do.cpp.orig	Fri Aug 19 17:50:40 2005
+++ src/scd_do.cpp	Fri Aug 19 17:51:06 2005
@@ -472,7 +472,7 @@
             return FALSE;
          }
          CHP = 16101;
-         while ((tmt = strchr(_Tpl->Body,'\n')) != NULL) *tmt = '\r';
+         while ((tmt = strchr((char *) _Tpl->Body,'\n')) != NULL) *tmt = '\r';
          tmt = m._Body;
          CHP = 16102;
          m._Body = (char *) malloc(((tmt != NULL) ? strlen(tmt) : 0) + strlen(_Tpl->Body) + 1);
@@ -787,4 +787,4 @@
    return TRUE;
 }
 
-#endif
\ No newline at end of file
+#endif
