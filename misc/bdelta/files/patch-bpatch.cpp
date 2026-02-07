--- bpatch.cpp.orig	2013-01-30 20:16:01 UTC
+++ bpatch.cpp
@@ -7,6 +7,8 @@
 #include "file.h"
 #include "compatibility.h"
 
+#define FEFE
+
 bool copy_bytes_to_file(FILE *infile, FILE *outfile, unsigned numleft) {
 	size_t numread;
 	do {
@@ -42,10 +44,17 @@ int main(int argc, char **argv) {
 			return 1;
 		}
 		unsigned short version = read_word(patchfile);
+#ifdef FEFE
+		if (version != 1 && version != 2) {
+			printf("unsupported patch version\n");
+			return 1;
+		}
+#else
 		if (version != 1) {
 			printf("unsupported patch version\n");
 			return 1;
 		}
+#endif
 		char intsize;
 		fread_fixed(patchfile, &intsize, 1);
 		if (intsize != 4) {
@@ -57,14 +66,32 @@ int main(int argc, char **argv) {
 
 		unsigned nummatches = read_dword(patchfile);
 
+#ifdef FEFE
+		long long * copyloc1 = new long long[nummatches + 1];
+		long long * copyloc2 = new long long[nummatches + 1];
+		unsigned *  copynum = new unsigned[nummatches + 1];
+#else
 		unsigned * copyloc1 = new unsigned[nummatches + 1];
 		unsigned * copyloc2 = new unsigned[nummatches + 1];
 		unsigned *  copynum = new unsigned[nummatches + 1];
+#endif
 
 		for (unsigned i = 0; i < nummatches; ++i) {
+#ifdef FEFE
+		  if (version==2) {
+			copyloc1[i] = read_varint(patchfile);
+			copyloc2[i] = read_varint(patchfile);
+			copynum[i] = read_varint(patchfile);
+		  } else {
 			copyloc1[i] = read_dword(patchfile);
 			copyloc2[i] = read_dword(patchfile);
 			copynum[i] = read_dword(patchfile);
+		  }
+#else
+			copyloc1[i] = read_dword(patchfile);
+			copyloc2[i] = read_dword(patchfile);
+			copynum[i] = read_dword(patchfile);
+#endif
 			size2 -= copyloc2[i] + copynum[i];
 		}
 		if (size2) {
@@ -77,16 +104,22 @@ int main(int argc, char **argv) {
 		FILE *outfile = fopen(argv[2], "wb");
 
 		for (unsigned i = 0; i < nummatches; ++i) {
+//			printf("%u/%u: copy %u bytes from patch file ofs %ld (dest ofs %u)\n",i,nummatches,copyloc2[i],ftell(patchfile),ftell(outfile));
 			if (!copy_bytes_to_file(patchfile, outfile, copyloc2[i])) {
 				printf("Error.  patchfile is truncated\n");
 				return -1;
 			}
 
-			int copyloc = copyloc1[i];
+			long long copyloc = copyloc1[i];
 			fseek(ref, copyloc, SEEK_CUR);
 
+			long curofs=ftell(ref);
+
+#ifdef FEFE
+//			printf("%u/%u: (%d -> %u,%d -> %u,%u)\n",i,nummatches-1,copyloc,ftell(ref),copyloc2[i],ftell(outfile),copynum[i]);
+#endif
 			if (!copy_bytes_to_file(ref, outfile, copynum[i])) {
-				printf("Error while copying from reference file\n");
+				printf("Error while copying from reference file (ofs %ld, %u bytes)\n", curofs, copynum[i]);
 				return -1;
 			}
 		}
