--- src/enumeration.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/enumeration.cpp
@@ -72,7 +72,7 @@ void EnumerationAlgorithm::printProgress(int step)
       //      if(!(progressCounter&4095))
 	//      if(!(progressCounter&255))
       if(!(progressCounter&15))
-	log2 fprintf(Stderr,"Number of Gr\"obner Bases found %i\n",progressCounter);
+	gfan_log2 fprintf(Stderr,"Number of Gr\"obner Bases found %i\n",progressCounter);
       fflush(Stderr);
       step--;
     }
