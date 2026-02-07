--- src/mdiadapt.cpp.orig	2012-10-26 22:43:50.000000000 +0400
+++ src/mdiadapt.cpp	2014-09-02 15:33:55.000000000 +0400
@@ -21,6 +21,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 #include <cmath>
 #include <string>
 #include <assert.h>
+#include <vector>
 #include "util.h"
 #include "mfstream.h"
 #include "mempool.h"
@@ -1170,7 +1171,7 @@ int mdiadaptlm::saveBIN_per_word(char *f
   }
 	
 	
-  streampos pos[lmsize()+1];
+  vector<streampos> pos(lmsize()+1);
   int maxlev=lmsize();
   char buff[100];
   int isQuant=0; //savebin for quantized LM is not yet implemented
@@ -1420,7 +1421,7 @@ int mdiadaptlm::saveBIN_per_level(char *
     VERBOSE(2,"savebin: " << filename << "\n");
   }
 
-  streampos pos[lmsize()+1];
+  vector<streampos> pos(lmsize()+1);
   int maxlev=lmsize();
   char buff[100];
   int isQuant=0; //savebin for quantized LM is not yet implemented
@@ -1803,7 +1804,7 @@ int mdiadaptlm::saveARPA_per_level(char 
   fstream out(filename,ios::out);
   //  out.precision(15);
 
-  streampos pos[lmsize()+1];
+  vector<streampos> pos(lmsize()+1); 
   table_entry_pos_t num[lmsize()+1];
   char buff[100];
 
