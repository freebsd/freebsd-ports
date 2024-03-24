--- zap/src/main/java/org/parosproxy/paros/Constant.java.orig	2024-03-24 00:03:43 UTC
+++ zap/src/main/java/org/parosproxy/paros/Constant.java
@@ -1405,9 +1405,19 @@ public final class Constant {
         return matcher.find();
     }
 
+    // Determine FreeBSD Operating System
+    // ZAP: Changed to final.
+    private static final Pattern patternFreeBSD = Pattern.compile("freebsd", Pattern.CASE_INSENSITIVE);
+
+    public static boolean isFreeBSD() {
+        String os_name = System.getProperty("os.name");
+        Matcher matcher = patternFreeBSD.matcher(os_name);
+        return matcher.find();
+    }
+
     // Determine Linux Operating System
     // ZAP: Changed to final.
-    private static final Pattern patternLinux = Pattern.compile("linux", Pattern.CASE_INSENSITIVE);
+    private static final Pattern patternLinux = Pattern.compile("linux|freebsd", Pattern.CASE_INSENSITIVE);
 
     public static boolean isLinux() {
         String os_name = System.getProperty("os.name");
