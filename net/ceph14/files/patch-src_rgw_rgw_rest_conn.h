diff --git a/src/rgw/rgw_rest_conn.h b/src/rgw/rgw_rest_conn.h
index 82047d24e5..9a210292b2 100644
--- src/rgw/rgw_rest_conn.h
+++ src/rgw/rgw_rest_conn.h
@@ -438,7 +438,7 @@ public:
   int wait(T *dest, E *err_result = nullptr);
 };
 
-template <class T, class E=int>
+template <class T, class E>
 int RGWRESTSendResource::wait(T *dest, E *err_result)
 {
   int ret = req.wait();
