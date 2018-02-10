--- src/hits_circle.cc.orig	2018-02-04 09:36:17 UTC
+++ src/hits_circle.cc
@@ -24,7 +24,7 @@ int Hits_Circle::create(unsigned int passed_size)
 	}
 
 	reqcount = bytecount = 0;
-	memset(rc_summary, (char) NULL, sizeof(rc_summary));
+	memset(rc_summary, 0, sizeof(rc_summary));
 
 	return 0;
 }
