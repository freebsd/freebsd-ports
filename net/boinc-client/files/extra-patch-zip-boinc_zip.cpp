--- zip/boinc_zip.cpp.orig	Sun Jan  2 13:29:37 2005
+++ zip/boinc_zip.cpp	Sun Mar 20 21:49:07 2005
@@ -129,7 +129,7 @@
 		//sz 3 onward will be each vector
 		int jj;
 		for (jj=0; jj<nVecSize; jj++)
-			strcpy(av[3+jj], pvectszFileIn->at(jj).c_str());
+			strcpy(av[3+jj], (*pvectszFileIn)[jj].c_str());
 	}
 	else 
 	{
@@ -141,7 +141,7 @@
 
 		// if they passed in a directory unzip there
 		if (carg == 4)
-			sprintf(av[3], "-d%s", pvectszFileIn->at(0).c_str());
+			sprintf(av[3], "-d%s", (*pvectszFileIn)[0].c_str());
 	}
 	// strcpy(av[carg-1], "");  // null arg	
 	// printf("args: %s %s %s %s\n", av[0], av[1], av[2], av[3]);
