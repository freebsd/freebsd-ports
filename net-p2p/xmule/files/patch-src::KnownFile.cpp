--- src/KnownFile.cpp.orig	Wed Apr 30 14:30:10 2003
+++ src/KnownFile.cpp	Mon May 26 12:46:29 2003
@@ -271,6 +271,73 @@
 	return ferror(file);
 }
 
+static void MD4Transform(uint32 Hash[4], uint32 x[16])
+{
+  uint32 a = Hash[0];
+  uint32 b = Hash[1];
+  uint32 c = Hash[2];
+  uint32 d = Hash[3];
+
+  /* Round 1 */
+  MD4_FF(a, b, c, d, x[ 0], S11); // 01
+  MD4_FF(d, a, b, c, x[ 1], S12); // 02
+  MD4_FF(c, d, a, b, x[ 2], S13); // 03
+  MD4_FF(b, c, d, a, x[ 3], S14); // 04
+  MD4_FF(a, b, c, d, x[ 4], S11); // 05
+  MD4_FF(d, a, b, c, x[ 5], S12); // 06
+  MD4_FF(c, d, a, b, x[ 6], S13); // 07
+  MD4_FF(b, c, d, a, x[ 7], S14); // 08
+  MD4_FF(a, b, c, d, x[ 8], S11); // 09
+  MD4_FF(d, a, b, c, x[ 9], S12); // 10
+  MD4_FF(c, d, a, b, x[10], S13); // 11
+  MD4_FF(b, c, d, a, x[11], S14); // 12
+  MD4_FF(a, b, c, d, x[12], S11); // 13
+  MD4_FF(d, a, b, c, x[13], S12); // 14
+  MD4_FF(c, d, a, b, x[14], S13); // 15
+  MD4_FF(b, c, d, a, x[15], S14); // 16
+
+  /* Round 2 */
+  MD4_GG(a, b, c, d, x[ 0], S21); // 17
+  MD4_GG(d, a, b, c, x[ 4], S22); // 18
+  MD4_GG(c, d, a, b, x[ 8], S23); // 19
+  MD4_GG(b, c, d, a, x[12], S24); // 20
+  MD4_GG(a, b, c, d, x[ 1], S21); // 21
+  MD4_GG(d, a, b, c, x[ 5], S22); // 22
+  MD4_GG(c, d, a, b, x[ 9], S23); // 23
+  MD4_GG(b, c, d, a, x[13], S24); // 24
+  MD4_GG(a, b, c, d, x[ 2], S21); // 25
+  MD4_GG(d, a, b, c, x[ 6], S22); // 26
+  MD4_GG(c, d, a, b, x[10], S23); // 27
+  MD4_GG(b, c, d, a, x[14], S24); // 28
+  MD4_GG(a, b, c, d, x[ 3], S21); // 29
+  MD4_GG(d, a, b, c, x[ 7], S22); // 30
+  MD4_GG(c, d, a, b, x[11], S23); // 31
+  MD4_GG(b, c, d, a, x[15], S24); // 32
+
+  /* Round 3 */
+  MD4_HH(a, b, c, d, x[ 0], S31); // 33
+  MD4_HH(d, a, b, c, x[ 8], S32); // 34
+  MD4_HH(c, d, a, b, x[ 4], S33); // 35
+  MD4_HH(b, c, d, a, x[12], S34); // 36
+  MD4_HH(a, b, c, d, x[ 2], S31); // 37
+  MD4_HH(d, a, b, c, x[10], S32); // 38
+  MD4_HH(c, d, a, b, x[ 6], S33); // 39
+  MD4_HH(b, c, d, a, x[14], S34); // 40
+  MD4_HH(a, b, c, d, x[ 1], S31); // 41
+  MD4_HH(d, a, b, c, x[ 9], S32); // 42
+  MD4_HH(c, d, a, b, x[ 5], S33); // 43
+  MD4_HH(b, c, d, a, x[13], S34); // 44
+  MD4_HH(a, b, c, d, x[ 3], S31); // 45
+  MD4_HH(d, a, b, c, x[11], S32); // 46
+  MD4_HH(c, d, a, b, x[ 7], S33); // 47
+  MD4_HH(b, c, d, a, x[15], S34); // 48
+
+  Hash[0] += a;
+  Hash[1] += b;
+  Hash[2] += c;
+  Hash[3] += d;
+}
+
 void CKnownFile::CreateHashFromInput(FILE* file,CFile* file2, int Length, uchar* Output, uchar* in_string) { 
 	// time critial
 	bool PaddingStarted = false;
@@ -342,73 +409,6 @@
   return m_iPartCount>0?m_iPartCount:(m_iPartCount=((m_nFileSize+(PARTSIZE-1))/PARTSIZE));
 }
 #endif
-
-static void MD4Transform(uint32 Hash[4], uint32 x[16])
-{
-  uint32 a = Hash[0];
-  uint32 b = Hash[1];
-  uint32 c = Hash[2];
-  uint32 d = Hash[3];
-
-  /* Round 1 */
-  MD4_FF(a, b, c, d, x[ 0], S11); // 01
-  MD4_FF(d, a, b, c, x[ 1], S12); // 02
-  MD4_FF(c, d, a, b, x[ 2], S13); // 03
-  MD4_FF(b, c, d, a, x[ 3], S14); // 04
-  MD4_FF(a, b, c, d, x[ 4], S11); // 05
-  MD4_FF(d, a, b, c, x[ 5], S12); // 06
-  MD4_FF(c, d, a, b, x[ 6], S13); // 07
-  MD4_FF(b, c, d, a, x[ 7], S14); // 08
-  MD4_FF(a, b, c, d, x[ 8], S11); // 09
-  MD4_FF(d, a, b, c, x[ 9], S12); // 10
-  MD4_FF(c, d, a, b, x[10], S13); // 11
-  MD4_FF(b, c, d, a, x[11], S14); // 12
-  MD4_FF(a, b, c, d, x[12], S11); // 13
-  MD4_FF(d, a, b, c, x[13], S12); // 14
-  MD4_FF(c, d, a, b, x[14], S13); // 15
-  MD4_FF(b, c, d, a, x[15], S14); // 16
-
-  /* Round 2 */
-  MD4_GG(a, b, c, d, x[ 0], S21); // 17
-  MD4_GG(d, a, b, c, x[ 4], S22); // 18
-  MD4_GG(c, d, a, b, x[ 8], S23); // 19
-  MD4_GG(b, c, d, a, x[12], S24); // 20
-  MD4_GG(a, b, c, d, x[ 1], S21); // 21
-  MD4_GG(d, a, b, c, x[ 5], S22); // 22
-  MD4_GG(c, d, a, b, x[ 9], S23); // 23
-  MD4_GG(b, c, d, a, x[13], S24); // 24
-  MD4_GG(a, b, c, d, x[ 2], S21); // 25
-  MD4_GG(d, a, b, c, x[ 6], S22); // 26
-  MD4_GG(c, d, a, b, x[10], S23); // 27
-  MD4_GG(b, c, d, a, x[14], S24); // 28
-  MD4_GG(a, b, c, d, x[ 3], S21); // 29
-  MD4_GG(d, a, b, c, x[ 7], S22); // 30
-  MD4_GG(c, d, a, b, x[11], S23); // 31
-  MD4_GG(b, c, d, a, x[15], S24); // 32
-
-  /* Round 3 */
-  MD4_HH(a, b, c, d, x[ 0], S31); // 33
-  MD4_HH(d, a, b, c, x[ 8], S32); // 34
-  MD4_HH(c, d, a, b, x[ 4], S33); // 35
-  MD4_HH(b, c, d, a, x[12], S34); // 36
-  MD4_HH(a, b, c, d, x[ 2], S31); // 37
-  MD4_HH(d, a, b, c, x[10], S32); // 38
-  MD4_HH(c, d, a, b, x[ 6], S33); // 39
-  MD4_HH(b, c, d, a, x[14], S34); // 40
-  MD4_HH(a, b, c, d, x[ 1], S31); // 41
-  MD4_HH(d, a, b, c, x[ 9], S32); // 42
-  MD4_HH(c, d, a, b, x[ 5], S33); // 43
-  MD4_HH(b, c, d, a, x[13], S34); // 44
-  MD4_HH(a, b, c, d, x[ 3], S31); // 45
-  MD4_HH(d, a, b, c, x[11], S32); // 46
-  MD4_HH(c, d, a, b, x[ 7], S33); // 47
-  MD4_HH(b, c, d, a, x[15], S34); // 48
-
-  Hash[0] += a;
-  Hash[1] += b;
-  Hash[2] += c;
-  Hash[3] += d;
-}
 
 // Adde by Tarod [Juanjo]
 void CAbstractFile::SetFileName(char* NewName) 
