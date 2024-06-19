--- third_party/unrar/src/crypt.cpp.orig	2024-05-21 18:07:39 UTC
+++ third_party/unrar/src/crypt.cpp
@@ -114,6 +114,8 @@ void GetRnd(byte *RndBuf,size_t BufSize)
     Success=CryptGenRandom(hProvider, (DWORD)BufSize, RndBuf) == TRUE;
     CryptReleaseContext(hProvider, 0);
   }
+#elif defined(__OpenBSD__)
+  arc4random_buf(RndBuf, BufSize);
 #elif defined(_UNIX)
   FILE *rndf = fopen("/dev/urandom", "r");
   if (rndf!=NULL)
