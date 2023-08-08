--- src/sflow.c.orig	2022-12-31 19:17:17 UTC
+++ src/sflow.c
@@ -326,7 +326,7 @@ void decodeIPV6(SFSample *sample)
 
 void decodeIPV6(SFSample *sample)
 {
-  u_int32_t label;
+  u_int32_t label __attribute__((unused));
   u_int32_t nextHeader;
   u_char *end = sample->header + sample->headerLen;
 
