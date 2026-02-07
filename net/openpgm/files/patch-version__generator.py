--- version_generator.py.orig	2012-12-04 02:57:22 UTC
+++ version_generator.py
@@ -8,7 +8,7 @@ build_date = time.strftime ("%Y-%m-%d")
 build_time = time.strftime ("%H:%M:%S")
 build_rev = filter (str.isdigit, "$Revision: 1487 $")
 
-print """
+print("""
 /* vim:ts=8:sts=8:sw=4:noai:noexpandtab
  * 
  * OpenPGM version.
@@ -50,6 +50,6 @@ const char* pgm_build_revision = "%s";
 
 
 /* eof */
-"""%(build_date, build_time, platform.system(), platform.machine(), build_rev)
+"""%(build_date, build_time, platform.system(), platform.machine(), build_rev))
 
 # end of file
