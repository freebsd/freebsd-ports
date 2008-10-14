--- src/java/com/thoughtworks/xstream/core/JVM.java.orig	2008-10-14 17:40:37.000000000 +0200
+++ src/java/com/thoughtworks/xstream/core/JVM.java	2008-10-14 17:47:39.000000000 +0200
@@ -67,6 +67,10 @@ public class JVM {
         return vendor.indexOf("Sun") != -1;
     }
 
+    private static boolean isDiablo() {
+        return vendor.indexOf("The FreeBSD Foundation") != -1;
+    }
+
     private static boolean isApple() {
         return vendor.indexOf("Apple") != -1;
     }
@@ -178,7 +182,7 @@ public class JVM {
     }
 
     private boolean canUseSun14ReflectionProvider() {
-        return (isSun() || isApple() || isHPUX() || isIBM() || isBlackdown() || isBEAWithUnsafeSupport() || isHitachi() || isSAP()) && is14() && loadClass("sun.misc.Unsafe") != null;
+        return (isSun() || isDiablo() || isApple() || isHPUX() || isIBM() || isBlackdown() || isBEAWithUnsafeSupport() || isHitachi() || isSAP()) && is14() && loadClass("sun.misc.Unsafe") != null;
     }
 
     private boolean canUseHarmonyReflectionProvider() {
