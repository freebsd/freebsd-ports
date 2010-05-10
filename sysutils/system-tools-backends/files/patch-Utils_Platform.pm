--- Utils/Platform.pm.orig	2010-04-02 00:17:39.000000000 +0200
+++ Utils/Platform.pm	2010-04-02 00:18:30.000000000 +0200
@@ -73,6 +73,7 @@ my $PLATFORM_INFO = {
   "freebsd-6"       => [ "FreeBSD", "6", "" ],
   "freebsd-7"       => [ "FreeBSD", "7", "" ],
   "freebsd-8"       => [ "FreeBSD", "8", "" ],
+  "freebsd-9"       => [ "FreeBSD", "9", "" ],
   "gentoo"          => [ "Gentoo Linux", "", "" ],
   "vlos-1.2"        => [ "Vida Linux OS", "1.2" ],
   "archlinux"       => [ "Arch Linux", "", "" ],
@@ -126,6 +127,7 @@ sub ensure_distro_map
      "freebsd-6"        => "freebsd-5",
      "freebsd-7"        => "freebsd-5",
      "freebsd-8"        => "freebsd-5",
+     "freebsd-9"        => "freebsd-5",
      "openna-1.0"       => "redhat-6.2",
      "pld-1.1"          => "pld-1.0",
      "pld-1.99"         => "pld-1.0",
