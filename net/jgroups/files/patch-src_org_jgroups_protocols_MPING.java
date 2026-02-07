--- src/org/jgroups/protocols/MPING.java.orig	2011-03-18 10:35:23.000000000 +0100
+++ src/org/jgroups/protocols/MPING.java	2011-03-18 10:37:30.000000000 +0100
@@ -29,7 +29,7 @@
 
 
     static {
-        can_bind_to_mcast_addr=Util.checkForLinux() || Util.checkForSolaris() || Util.checkForHp();
+        can_bind_to_mcast_addr=Util.checkForFreeBSD() || Util.checkForLinux() || Util.checkForSolaris() || Util.checkForHp();
     }
 
 
