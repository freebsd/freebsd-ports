--- src/org/jgroups/protocols/TP.java.orig	2011-03-18 10:39:08.000000000 +0100
+++ src/org/jgroups/protocols/TP.java	2011-03-18 10:39:37.000000000 +0100
@@ -63,7 +63,7 @@
     protected static NumberFormat f;
 
     static {
-        can_bind_to_mcast_addr=Util.checkForLinux() || Util.checkForSolaris() || Util.checkForHp();
+        can_bind_to_mcast_addr=Util.checkForFreeBSD() || Util.checkForLinux() || Util.checkForSolaris() || Util.checkForHp();
         f=NumberFormat.getNumberInstance();
         f.setGroupingUsed(false);
         f.setMaximumFractionDigits(2);
