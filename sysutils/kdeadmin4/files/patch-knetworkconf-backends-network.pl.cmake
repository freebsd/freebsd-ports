--- knetworkconf/backends/network.pl.cmake.orig	2010-01-05 15:48:32.209103654 +0100
+++ knetworkconf/backends/network.pl.cmake	2010-01-05 17:04:04.405595464 +0100
@@ -91,30 +91,21 @@
 
 sub gst_network_get_freebsd_wireless_ifaces
 {
-  my ($fd, $line, $iface);
-  my (@ifaces, $command);
+  my $file = "/etc/rc.conf";
+  my ($fd, $i, @ret);
 
-  $command = &gst_file_get_cmd_path ("iwconfig");
-  open $fd, "$command |";
-  return @ifaces if $fd eq undef;
+  $fd = &gst_file_open_read_from_names ($file);
+  return @ret if !$fd;
 
-  while (<$fd>)
-  {
-    if (/^([a-zA-Z]+[0-9]+):/)
+  while ($i = <$fd>)
     {
-      $iface = $1;
-    }
-
-    if (/media:.*wireless.*/i)
+    if ($i =~ /^wlans_.*[ \t]*=[ \t]*(.*)/)
     {
-      push @ifaces, $iface;
+      push @ret, $1;
     }
   }
 
-  &gst_file_close ($fd);
-  &gst_report_leave ();
-
-  return \@ifaces;
+  return \@ret;
 }
 
 # Returns an array with the wireless devices found
@@ -142,7 +133,9 @@
     $command  = $command_ifconfig if ($$tool{"system"} eq "FreeBSD");
 
     $command .= " $dev";
-    $command .= " essid '$essid'" if ($essid);
+    $command .= " essid" if ($$tool{"system"} eq "Linux");
+    $command .= " ssid" if ($$tool{"system"} eq "FreeBSD");
+    $command .= " '$essid'";
 
     if ($key)
     {
@@ -541,6 +534,9 @@
        "vlos-1.2"     => "debian-2.2",
        "freebsd-5"    => "debian-2.2",
        "freebsd-6"    => "debian-2.2",
+       "freebsd-7"    => "debian-2.2",
+       "freebsd-8"    => "debian-2.2",
+       "freebsd-9"    => "debian-2.2",
        "ark"          => "redhat-6.2",
        );
 
@@ -1842,6 +1838,9 @@
 	  "gentoo"       => \&gst_network_deb22_get_file,
 	  "freebsd-5"    => \&gst_network_deb22_get_file,
 	  "freebsd-6"    => \&gst_network_deb22_get_file,
+	  "freebsd-7"    => \&gst_network_deb22_get_file,
+	  "freebsd-8"    => \&gst_network_deb22_get_file,
+	  "freebsd-9"    => \&gst_network_deb22_get_file,
 	  "ark"          => \&get_network_rh62_get_file,
 	  );
 
@@ -3965,6 +3964,9 @@
 	  "vlos-1.2"     => "",
 	  "freebsd-5"    => "",
 	  "freebsd-6"    => "",
+	  "freebsd-7"    => "",
+	  "freebsd-8"    => "",
+	  "freebsd-9"    => "",
 	  "ark"          => "lo",
 	  );
 
@@ -4113,6 +4115,9 @@
 	  "vlos-1.2"     => "vlos-1.2",
 	  "freebsd-5"    => "freebsd-5",
 	  "freebsd-6"    => "freebsd-5",
+	  "freebsd-7"    => "freebsd-5",
+	  "freebsd-8"    => "freebsd-5",
+	  "freebsd-9"    => "freebsd-5",
 	  "ark"          => "ark",
 	  );
 
@@ -4612,6 +4617,9 @@
 	  "vlos-1.2"     => "vlos-1.2",
 	  "freebsd-5"    => "freebsd-5",
 	  "freebsd-6"    => "freebsd-5",
+	  "freebsd-7"    => "freebsd-5",
+	  "freebsd-8"    => "freebsd-5",
+	  "freebsd-9"    => "freebsd-5",
 	  "ark"          => "ark",
 	  );
   
@@ -5506,6 +5514,9 @@
 	  "vlos-1.2"     => "vlos-1.2",
 	  "freebsd-5"    => "freebsd-5",
 	  "freebsd-6"    => "freebsd-5",
+	  "freebsd-7"    => "freebsd-5",
+	  "freebsd-8"    => "freebsd-5",
+	  "freebsd-9"    => "freebsd-5",
 	  );
 
   my %dist_tables =
@@ -5955,6 +5966,9 @@
 	  "vlos-1.2"     => "vlos-1.2",
 	  "freebsd-5"    => "freebsd-5",
 	  "freebsd-6"    => "freebsd-5",
+	  "freebsd-7"    => "freebsd-5",
+	  "freebsd-8"    => "freebsd-5",
+	  "freebsd-9"    => "freebsd-5",
 	  );
 
   my %dist_tables =
