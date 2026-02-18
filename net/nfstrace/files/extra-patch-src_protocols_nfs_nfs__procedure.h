--- src/protocols/nfs/nfs_procedure.h.orig	2017-01-31 21:48:12 UTC
+++ src/protocols/nfs/nfs_procedure.h
@@ -117,8 +117,7 @@ class NFSProcedure : public NST::API::RPCProcedure (pr
     ResType* pres;
 
 private:
-    inline static bool_t return_true(XDR*, void*, ...) { return 1; }
-    inline static bool_t return_true(XDR*, ...) { return 1; }
+    inline static bool_t return_true(XDR*, void*) { return 1; }
     ArgType              arg;
     ResType              res;
 };
