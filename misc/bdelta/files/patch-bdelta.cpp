--- bdelta.cpp.orig	2013-01-30 20:16:01 UTC
+++ bdelta.cpp
@@ -10,6 +10,8 @@
 #include "file.h"
 #include "compatibility.h"
 
+#define FEFE
+
 const void *f_read(void *f, void *buf, unsigned place, unsigned num) {
 	fseek((FILE *)f, place, SEEK_SET);
 	fread_fixed((FILE *)f, buf, num);
@@ -103,9 +105,15 @@ int main(int argc, char **argv) {
 
 		nummatches = bdelta_numMatches(b);
 
+#ifdef FEFE
+		long long * copyloc1 = new long long[nummatches + 1];
+		long long * copyloc2 = new long long[nummatches + 1];
+		unsigned *  copynum = new unsigned[nummatches + 1];
+#else
 		unsigned * copyloc1 = new unsigned[nummatches + 1];
 		unsigned * copyloc2 = new unsigned[nummatches + 1];
 		unsigned *  copynum = new unsigned[nummatches + 1];
+#endif
 
 		FILE *fout = fopen(argv[3], "wb");
 		if (!fout) {
@@ -115,7 +123,7 @@ int main(int argc, char **argv) {
 
 		const char *magic = "BDT";
 		fwrite_fixed(fout, magic, 3);
-		unsigned short version = 1;
+		unsigned short version = 2;
 		write_word(fout, version);
 		unsigned char intsize = 4;
 		fwrite_fixed(fout, &intsize, 1);
@@ -129,12 +137,22 @@ int main(int argc, char **argv) {
 			unsigned p1, p2, num;
 			bdelta_getMatch(b, i, &p1, &p2, &num);
 			// printf("%*x, %*x, %*x, %*x\n", 10, p1, 10, p2, 10, num, 10, p2-lastp2);
+#ifdef FEFE
+			copyloc1[i] = (long long)p1 - lastp1;
+			copyloc2[i] = (long long)p2 - lastp2;
+			copynum[i] = num;
+			write_varint(fout, copyloc1[i]);
+			write_varint(fout, copyloc2[i]);
+			write_varint(fout, copynum[i]);
+//			printf("%u/%u: (%ld -> %u,%ld -> %u,%u)\n",i,nummatches,copyloc1[i],p1,copyloc2[i],p2,copynum[i]);
+#else
 			copyloc1[i] = p1 - lastp1;
 			write_dword(fout, copyloc1[i]);
 			copyloc2[i] = p2 - lastp2;
 			write_dword(fout, copyloc2[i]);
 			copynum[i] = num;
 			write_dword(fout, copynum[i]);
+#endif
 			lastp1 = p1 + num;
 			lastp2 = p2 + num;
 		}
