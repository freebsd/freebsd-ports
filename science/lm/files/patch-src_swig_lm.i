--- src/swig/lm.i.orig	2018-09-09 20:47:46 UTC
+++ src/swig/lm.i
@@ -66,7 +66,7 @@ using lm::rdme::InvalidParticleException
 %}
 
 %inline %{
-typedef long time_t;
+//typedef long time_t;
 typedef unsigned char       uchar;
 typedef unsigned int        uint;
 typedef unsigned long       ulong;
