--- coda-src/venus/fso.h.orig	Fri Aug  6 23:31:46 2004
+++ coda-src/venus/fso.h	Fri Aug  6 23:32:05 2004
@@ -537,7 +537,7 @@
     void DetachHdbBindings();
     void DetachHdbBinding(binding *, int =0);
     int PredetermineFetchState(int, int);
-    void SetFetchAllowed(enum HoardFetchState new_state)
+    void SetFetchAllowed(HoardFetchState new_state)
         { FetchAllowed = new_state; }
     int IsFetchAllowed()
         { if (FetchAllowed == HF_Fetch) 
@@ -545,7 +545,7 @@
           else 
               return 0; 
         }
-    void SetAskingAllowed(enum HoardAskState new_state)
+    void SetAskingAllowed(HoardAskState new_state)
         { AskingAllowed = new_state; }
     int IsAskingAllowed()
         { if (AskingAllowed == HA_Ask)
