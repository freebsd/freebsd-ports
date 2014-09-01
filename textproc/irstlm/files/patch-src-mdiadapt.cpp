--- src/mdiadapt.cpp.orig	2014-09-01 15:41:52.000000000 +0400
+++ src/mdiadapt.cpp	2014-09-01 15:46:52.000000000 +0400
@@ -1170,7 +1170,7 @@ int mdiadaptlm::saveBIN_per_word(char *f
   }
 	
 	
-  streampos pos[lmsize()+1];
+  streampos *pos = new streampos[lmsize()+1];
   int maxlev=lmsize();
   char buff[100];
   int isQuant=0; //savebin for quantized LM is not yet implemented
@@ -1385,7 +1385,7 @@ int mdiadaptlm::saveBIN_per_word(char *f
     out.seekp(pos[i]);
     out << buff;
   }
-	
+	delete[] pos;
 	out.close();
 	
   //concatenate files for each single level into one file
@@ -1420,7 +1420,7 @@ int mdiadaptlm::saveBIN_per_level(char *
     VERBOSE(2,"savebin: " << filename << "\n");
   }
 
-  streampos pos[lmsize()+1];
+  streampos *pos = new streampos[lmsize()+1];
   int maxlev=lmsize();
   char buff[100];
   int isQuant=0; //savebin for quantized LM is not yet implemented
@@ -1583,6 +1583,7 @@ int mdiadaptlm::saveBIN_per_level(char *
     out << buff;
   }
   out.close();
+  delete[] pos;
 
   //concatenate files for each single level into one file
 	//single level files should have a name derived from "filename"
@@ -1803,7 +1804,7 @@ int mdiadaptlm::saveARPA_per_level(char 
   fstream out(filename,ios::out);
   //  out.precision(15);
 
-  streampos pos[lmsize()+1];
+  streampos *pos = new streampos[lmsize()+1]; 
   table_entry_pos_t num[lmsize()+1];
   char buff[100];
 
@@ -1955,6 +1956,7 @@ int mdiadaptlm::saveARPA_per_level(char 
     out << buff;
   }
 
+  delete[] pos;
   out.seekp(last);
   out << "\\end\\" << "\n";
   system("date");
