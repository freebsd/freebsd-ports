--- scheduler/cups-driverd.cxx.orig	2015-06-12 01:21:05 UTC
+++ scheduler/cups-driverd.cxx
@@ -913,7 +913,7 @@ get_file(const char *name,		/* I - Name 
   }
   else
 
-#elif defined(__linux)
+#elif defined(__linux) || defined(__FreeBSD__) || defined(__DragonFly__)
   if (!strncmp(name, "lsb/usr/", 8))
   {
    /*
@@ -1093,7 +1093,7 @@ list_ppds(int        request_id,	/* I - 
   load_ppds("/System/Library/Printers/PPDs/Contents/Resources/en.lproj",
             "System/Library/Printers/PPDs/Contents/Resources/en.lproj", 0);
 
-#elif defined(__linux)
+#elif defined(__linux) || defined(__FreeBSD__) || defined(__DragonFly__)
  /*
   * Load PPDs from LSB-defined locations...
   */
