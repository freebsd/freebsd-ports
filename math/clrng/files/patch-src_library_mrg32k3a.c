--- src/library/mrg32k3a.c.orig	2026-09-06 13:27:06 UTC
+++ src/library/mrg32k3a.c
@@ -404,21 +404,21 @@ clrngStatus clrngMrg32k3aWriteStreamInfo(const clrngMr
 	// The Initial state of the Stream
 	fprintf(file, "\n   initial = { ");
 	for (size_t i = 0; i < 3; i++)
-		fprintf(file, "%lu, ", stream->initial.g1[i]);
+		fprintf(file, "%ju, ", (uintmax_t)stream->initial.g1[i]);
 
 	for (size_t i = 0; i < 2; i++)
-		fprintf(file, "%lu, ", stream->initial.g2[i]);
+		fprintf(file, "%ju, ", (uintmax_t)stream->initial.g2[i]);
 
-	fprintf(file, "%lu }\n", stream->initial.g2[2]);
+	fprintf(file, "%ju }\n", (uintmax_t)stream->initial.g2[2]);
 	//The Current state of the Stream
 	fprintf(file, "\n   Current = { ");
 	for (size_t i = 0; i < 3; i++)
-		fprintf(file, "%lu, ", stream->current.g1[i]);
+		fprintf(file, "%ju, ", (uintmax_t)stream->current.g1[i]);
 
 	for (size_t i = 0; i < 2; i++)
-		fprintf(file, "%lu, ", stream->current.g2[i]);
+		fprintf(file, "%ju, ", (uintmax_t)stream->current.g2[i]);
 
-	fprintf(file, "%lu }\n", stream->current.g2[2]);
+	fprintf(file, "%ju }\n", (uintmax_t)stream->current.g2[2]);
 
 	return CLRNG_SUCCESS;
 }
