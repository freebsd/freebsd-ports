--- src/config.h.orig	2025-10-02 19:33:23 UTC
+++ src/config.h
@@ -44,7 +44,7 @@ inline constexpr std::array<ImageSize, 6> AllowedIconS
 /**
  * Fake package name AppStream Generator uses internally to inject additional metainfo on users' request
  */
-inline constexpr std::string EXTRA_METAINFO_FAKE_PKGNAME = "+extra-metainfo";
+inline const std::string EXTRA_METAINFO_FAKE_PKGNAME = "+extra-metainfo";
 
 /**
  * Describes a suite in a software repository.
