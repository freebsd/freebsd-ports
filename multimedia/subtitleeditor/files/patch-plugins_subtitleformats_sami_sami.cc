--- plugins/subtitleformats/sami/sami.cc.orig	2014-02-12 22:02:58 UTC
+++ plugins/subtitleformats/sami/sami.cc
@@ -263,7 +263,7 @@ public:
 					{
 						inptr = (char *)(line.c_str());
 						p = tmptext;
-						p = '\0';
+						*p = '\0';
 
 						state = SAMI_STATE_INIT;
 						continue;
