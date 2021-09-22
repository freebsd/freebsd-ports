--- src/sflow.c.orig	2020-05-10 13:57:54 UTC
+++ src/sflow.c
@@ -306,7 +306,7 @@ void decodeIPV4(SFSample *sample)
 
 void decodeIPV6(SFSample *sample)
 {
-  u_int32_t label;
+  u_int32_t label __attribute__((unused));
   u_int32_t nextHeader;
   u_char *end = sample->header + sample->headerLen;
 
