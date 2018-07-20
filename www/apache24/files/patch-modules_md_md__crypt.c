Upstream https://svn.apache.org/viewvc?view=revision&revision=1836096

On the 2.4.x branch:

merge r1836095 from trunk:
* using the, hopefully correct, ever elusive libressl version numbering check
  for the new openssl API calls, fixes PR 62548.

--- modules/md/md_crypt.c.orig	2018-06-29 11:53:50 UTC
+++ modules/md/md_crypt.c
@@ -52,7 +52,7 @@
 
 #if defined(LIBRESSL_VERSION_NUMBER)
 /* Missing from LibreSSL */
-#define MD_USE_OPENSSL_PRE_1_1_API (LIBRESSL_VERSION_NUMBER < 0x2080000f)
+#define MD_USE_OPENSSL_PRE_1_1_API (LIBRESSL_VERSION_NUMBER < 0x2070000f)
 #else /* defined(LIBRESSL_VERSION_NUMBER) */
 #define MD_USE_OPENSSL_PRE_1_1_API (OPENSSL_VERSION_NUMBER < 0x10100000L)
 #endif
