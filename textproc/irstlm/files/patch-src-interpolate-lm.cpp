--- src/interpolate-lm.cpp.orig	2014-09-01 15:59:41.000000000 +0400
+++ src/interpolate-lm.cpp	2014-09-01 16:00:21.000000000 +0400
@@ -230,7 +230,7 @@ int main(int argc, char **argv)
   //Learning mixture weights
   if (learn) {
 
-    std::vector<float> p[N]; //LM probabilities
+    std::vector<float> *p = new std::vector<float>[N]; //LM probabilities
     float c[N]; //expected counts
     float den,norm; //inner denominator, normalization term
     float variation=1.0; // global variation between new old params
@@ -256,6 +256,7 @@ int main(int argc, char **argv)
         lstream >> token >> id >> newlm;
         if(id <= 0 || id > N) {
           std::cerr << "LM id out of range." << std::endl;
+          delete[] p;
           return 1;
         }
         id--; // count from 0 now
@@ -318,6 +319,7 @@ int main(int argc, char **argv)
     outtxt << "LMINTERPOLATION " << N << "\n";
     for (int i=0; i<N; i++) outtxt << w[i] << " " << lmf[i] << "\n";
     outtxt.close();
+    delete[] p;
   }
 
   for(int i = 0; i < N; i++)
