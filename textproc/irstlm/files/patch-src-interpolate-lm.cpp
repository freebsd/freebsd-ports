--- src/interpolate-lm.cpp.orig	2012-10-02 11:06:58.000000000 +0400
+++ src/interpolate-lm.cpp	2014-09-02 14:42:03.000000000 +0400
@@ -230,7 +230,7 @@ int main(int argc, char **argv)
   //Learning mixture weights
   if (learn) {
 
-    std::vector<float> p[N]; //LM probabilities
+    std::vector< std::vector<float> > p(N); //LM probabilities
     float c[N]; //expected counts
     float den,norm; //inner denominator, normalization term
     float variation=1.0; // global variation between new old params
