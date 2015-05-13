--- osquery/tables/system/centos/rpm_packages.cpp.orig	2015-05-05 00:16:41 UTC
+++ osquery/tables/system/centos/rpm_packages.cpp
@@ -147,7 +147,7 @@ QueryData genRpmPackageFiles(QueryContex
       r["mode"] = lsperms(rpmfiFMode(fi));
       r["size"] = BIGINT(rpmfiFSize(fi));
 
-#ifdef CENTOS_CENTOS6
+#if defined(CENTOS_CENTOS6) || defined(RHEL_RHEL6)
       // Older versions of rpmlib/rpmip use a hash algorithm enum.
       pgpHashAlgo digest_algo;
 #else
