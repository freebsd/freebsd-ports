--- src/xml.h.orig	2018-02-10 07:20:10 UTC
+++ src/xml.h
@@ -100,7 +100,7 @@ public:
     void xmlout(const std::string &tag,const std::string &value){ xmlout(tag,value,"",true); }
     void xmlout(const std::string &tag,const int value){ xmlprintf(tag,"","%d",value); }
     void xmloutl(const std::string &tag,const long value){ xmlprintf(tag,"","%ld",value); }
-    void xmlout(const std::string &tag,const int64_t value){ xmlprintf(tag,"","%"PRId64,value); }
+    void xmlout(const std::string &tag,const int64_t value){ xmlprintf(tag,"","%" PRId64,value); }
     void xmlout(const std::string &tag,const double value){ xmlprintf(tag,"","%f",value); }
     void xmlout(const std::string &tag,const struct timeval &ts){
 	xmlprintf(tag,"","%d.%06d",(int)ts.tv_sec, (int)ts.tv_usec);
