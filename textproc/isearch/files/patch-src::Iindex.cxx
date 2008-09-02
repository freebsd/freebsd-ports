--- src/Iindex.cxx.orig	2008-08-10 22:50:36.000000000 -0500
+++ src/Iindex.cxx	2008-08-10 22:52:14.000000000 -0500
@@ -170,7 +170,7 @@
 	}
       }
       if (Found) {
-	Offset = (GPTYPE)((UINT4)Found - (UINT4)Buffer);
+	Offset = (GPTYPE)((UINT8)Found - (UINT8)Buffer);
 	/* the separator marks the beginning of the next 
 	   record. (offset - 1), then marks the end of 
 	   the current record. we must make sure that the
