--- src/Main.cpp.orig	Thu Apr 15 12:08:27 2004
+++ src/Main.cpp	Thu Apr 15 12:08:40 2004
@@ -998,7 +998,6 @@
         else if (accel & MPEG2_ACCEL_SPARC_VIS2)
             printf("%s", _("Using Sparc VIS2 acceleration\n"));
 #endif
-        else
             printf("%s", _("Using no special acceleration\n"));
     
         if (!(mpeg2dec = mpeg2_init()))
