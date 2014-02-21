--- KIM_API/GNU_compiler_settings.mk.orig	2012-08-19 23:13:47.000000000 +0200
+++ KIM_API/GNU_compiler_settings.mk	2014-02-21 16:11:02.000000000 +0100
@@ -53,7 +53,3 @@
    # Add libforgranbegin if needed.
    LINKLIBFLAG += -lgfortranbegin
 endif
-ifdef KIM_DYNAMIC
-   # Add libdl if dynamic linking is being used
-   LINKLIBFLAG += -ldl
-endif
