--- source/paths.h.orig Sun Apr  6 00:00:00 1997
+++ source/paths.h      Fri Jul 18 19:18:09 2003
@@ -34,9 +34,9 @@
 #   define INC_XMU(aaa) <XMU_DIRECTORY/aaa>
 #   define INC_XAW(aaa) <XAW_DIRECTORY/aaa>
 #else
-#   define INC_X11(aaa) <X11/##aaa##>
-#   define INC_XMU(aaa) <X11/Xmu/##aaa##>
-#   define INC_XAW(aaa) <X11/Xaw3d/##aaa##>
+#   define INC_X11(aaa) <X11/aaa>
+#   define INC_XMU(aaa) <X11/Xmu/aaa>
+#   define INC_XAW(aaa) <X11/Xaw3d/aaa>
 #endif

 #endif /* _PATHS_H_ */
