--- lib/inc/facter/facts/fact.hpp.orig	2017-07-18 18:49:09 UTC
+++ lib/inc/facter/facts/fact.hpp
@@ -528,9 +528,9 @@ namespace facter { namespace facts {
         constexpr static char const* zfs_version = "zfs_version";
 
         /**
-         * The ZFS supported feature numbers.
+         * The ZFS supported version numbers.
          */
-        constexpr static char const* zfs_featurenumbers = "zfs_featurenumbers";
+        constexpr static char const* zfs_versionnumbers = "zfs_featurenumbers";
 
         /**
          * The ZFS storage pool (zpool) version fact.
@@ -538,9 +538,14 @@ namespace facter { namespace facts {
         constexpr static char const* zpool_version = "zpool_version";
 
         /**
-         * The ZFS storage pool supported feature numbers.
+         * The ZFS storage pool supported feature flags.
          */
-        constexpr static char const* zpool_featurenumbers = "zpool_featurenumbers";
+        constexpr static char const* zpool_featureflags = "zpool_featureflags";
+
+        /**
+         * The ZFS storage pool supported version numbers.
+         */
+        constexpr static char const* zpool_versionnumbers = "zpool_featurenumbers";
 
         /**
          * The fact for number of Solaris zones.
