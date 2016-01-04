--- setup.py.orig	2015-03-04 07:00:53 UTC
+++ setup.py
@@ -167,9 +167,10 @@ class build_clib(_build_clib):
         build_temp = os.path.abspath(self.build_temp)
 
         # Ensure our temporary build directory exists
+        print("YURI build_temp="+build_temp)
         try:
             os.makedirs(build_temp)
-        except IOError:
+        except:
             pass
 
         # Ensure all of our executanle files have their permission set
