--- coda-src/venus/fso.h.orig	Fri Aug  6 22:52:18 2004
+++ coda-src/venus/fso.h	Fri Aug  6 22:54:34 2004
@@ -539,7 +539,7 @@
     void DetachHdbBindings();
     void DetachHdbBinding(binding *, int =0);
     int PredetermineFetchState(int, int);
-    void SetFetchAllowed(enum HoardFetchState new_state)
+    void SetFetchAllowed(HoardFetchState new_state)
         { FetchAllowed = new_state; }
     int IsFetchAllowed()
         { if (FetchAllowed == HF_Fetch) 
@@ -547,7 +547,7 @@
           else 
               return 0; 
         }
-    void SetAskingAllowed(enum HoardAskState new_state)
+    void SetAskingAllowed(HoardAskState new_state)
         { AskingAllowed = new_state; }
     int IsAskingAllowed()
         { if (AskingAllowed == HA_Ask)
@@ -820,9 +820,8 @@
 #define	CFSOP_PRELUDE(str, comp, fid)\
 {\
     char buf[256];\
-    strcpy(buf, (comp));\
-    if (buf[0] == '\0')\
-	sprintf(buf, "%s", FID_(&(fid)));\
+    if (comp) strcpy(buf, (comp));\
+    else sprintf(buf, "%s", FID_(&(fid)));\
     MarinerLog((str), buf);\
 }
 #define	CFSOP_POSTLUDE(str)\
