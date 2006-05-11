--- knowndrives.c.orig  Wed Apr  5 23:50:07 2006
+++ knowndrives.c       Sun Apr 23 20:46:00 2006
@@ -562,6 +562,20 @@
     vendoropts_9_minutes,
     NULL, NULL
   },
+  { "Maxtor MaXLine Pro 500",
+    "^Maxtor 7H500[FR]0$",
+    ".*",
+    NULL,
+    vendoropts_9_minutes,
+    NULL, NULL
+  },
+  { "Maxtor MaXLine III family",
+    "^Maxtor 7[LV](30|25)0[FRS]0$",
+    ".*",
+    NULL,
+    vendoropts_9_minutes,
+    NULL, NULL
+  },
   { "Maxtor MaXLine Plus II",
     "^Maxtor 7Y250[PM]0$",
     ".*",
