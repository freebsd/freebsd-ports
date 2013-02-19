--- intl/unicharutil/util/nsUnicharUtils.h.orig	2012-10-28 10:53:41.000000000 +0100
+++ intl/unicharutil/util/nsUnicharUtils.h	2012-10-28 10:54:01.000000000 +0100
@@ -72,6 +72,8 @@ inline PRBool IsLowerCase(PRUnichar c) {
 class nsCaseInsensitiveStringComparator : public nsStringComparator
 {
 public:
+  nsCaseInsensitiveStringComparator() {}
+
   virtual int operator() (const PRUnichar*,
                           const PRUnichar*,
                           PRUint32 aLength) const;
