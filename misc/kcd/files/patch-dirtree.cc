--- dirtree.cc.orig	2009-02-18 13:01:05.000000000 +0100
+++ dirtree.cc	2013-05-27 18:11:32.183060000 +0200
@@ -25,6 +25,10 @@
 #include "cstrlib.h"
 #include "gentree.h"
 
+#ifdef HAVE_UNISTD_H
+# include <unistd.h>
+#endif
+
 sptr_list<DirectoryEntry> dirTree;
 
 const char	uniqueTag[] = "<KCDID#9>";	// File ID
@@ -170,12 +174,12 @@
 			ReadSaveFile(dirTree, filegz);
 		}
 		catch(ErrorBadFileFormat &) {
-			gzclose(file);
+			gzclose(filegz);
 			throw ErrorGenericFile(_("invalid file format in %$"), saveFile);
 
 		}
 		catch(ErrorGZIO &) {
-			gzclose(file);
+			gzclose(filegz);
 			throw ErrorGenericFile(_("error reading file %$"), saveFile);
 		}
 		gzclose(filegz);
