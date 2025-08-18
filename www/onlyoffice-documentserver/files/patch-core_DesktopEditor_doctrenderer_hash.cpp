--- core/DesktopEditor/doctrenderer/hash.cpp.orig	2025-08-02 18:33:34 UTC
+++ core/DesktopEditor/doctrenderer/hash.cpp
@@ -4,12 +4,12 @@
 #include "../common/Base64.h"
 #endif
 
-#include "openssl/sha.h"
-#include "openssl/md2.h"
-#include "openssl/md4.h"
-#include "openssl/md5.h"
-#include "openssl/whrlpool.h"
-#include "openssl/ripemd.h"
+#include <openssl/sha.h>
+#include <openssl/md2.h>
+#include <openssl/md4.h>
+#include <openssl/md5.h>
+#include <openssl/whrlpool.h>
+#include <openssl/ripemd.h>
 
 #include <cstring>
 #include <memory>
@@ -37,6 +37,7 @@ unsigned char* CHash::hash(const unsigned char* data, 
 
 	switch (alg)
 	{
+#if 0
 	case haMD2:
 	{
 		nBufLen = 16;
@@ -44,6 +45,7 @@ unsigned char* CHash::hash(const unsigned char* data, 
 		MD2(data, d, pBufData);
 		break;
 	}
+#endif
 	case haMD4:
 	{
 		nBufLen = 16;
@@ -246,11 +248,13 @@ void hash_iteration(unsigned char*& input, int iter, u
 
 	switch (alg)
 	{
+#if 0
 	case CHash::haMD2:
 	{
 		MD2(input, alg_size + 4, tmp);
 		break;
 	}
+#endif
 	case CHash::haMD4:
 	{
 		MD4(input, alg_size + 4, tmp);
@@ -319,6 +323,7 @@ unsigned char* CHash::hash2(const char* password, cons
 	unsigned char* pBuffer1 = NULL;
 	switch (alg)
 	{
+#if 0
 	case haMD2:
 	{
 		alg_size = 16;
@@ -326,6 +331,7 @@ unsigned char* CHash::hash2(const char* password, cons
 		MD2(inputData, inputDataLen, pBuffer1);
 		break;
 	}
+#endif
 	case haMD4:
 	{
 		alg_size = 16;
