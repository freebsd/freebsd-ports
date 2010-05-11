--- knetworkconf/backends/service.pl.cmake.orig	2010-01-05 17:05:28.885442778 +0100
+++ knetworkconf/backends/service.pl.cmake	2010-01-05 17:06:56.310432111 +0100
@@ -287,6 +287,9 @@
 
      "freebsd-5"      => "freebsd-5",
      "freebsd-6"      => "freebsd-5",
+     "freebsd-7"      => "freebsd-5",
+     "freebsd-8"      => "freebsd-5",
+     "freebsd-9"      => "freebsd-5",
 
      "ark"            => "redhat-5.2",
     );
@@ -1642,6 +1645,9 @@
 
        "freebsd-5"    => \&gst_service_rcng_get_status,
        "freebsd-6"    => \&gst_service_rcng_get_status,
+       "freebsd-7"    => \&gst_service_rcng_get_status,
+       "freebsd-8"    => \&gst_service_rcng_get_status,
+       "freebsd-9"    => \&gst_service_rcng_get_status,
 
        "ark"          => \&gst_service_redhat_get_status,
       );
