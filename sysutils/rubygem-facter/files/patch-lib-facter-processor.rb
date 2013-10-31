--- lib/facter/processor.rb.orig	2013-04-30 19:57:21.000000000 +0400
+++ lib/facter/processor.rb	2013-04-30 19:58:19.000000000 +0400
@@ -88,14 +88,14 @@
 end
 
 Facter.add("Processor") do
-  confine :kernel => :openbsd
+  confine :kernel => [ :openbsd, :freebsd ]
   setcode do
     Facter::Util::Resolution.exec("uname -p")
   end
 end
 
 Facter.add("ProcessorCount") do
-  confine :kernel => :openbsd
+  confine :kernel => [ :openbsd, :freebsd ]
   setcode do
     Facter::Util::Resolution.exec("sysctl -n hw.ncpu")
   end
