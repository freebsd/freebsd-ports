--- iiimsf/src/IMXMLUtil.cpp	Mon Oct  4 18:07:05 2004
+++ iiimsf/src/IMXMLUtil.cpp	Wed Feb 16 20:38:34 2005
@@ -78,7 +78,7 @@
 {
     IMXMLModifier xml((const char *)argv[1]);
     IMModuleInfoVec *lev;
-    string mod("/usr/lib/im/leif/freewnnle.so");
+    string mod(IM_DIRECTORY "/leif/freewnnle.so");
     string lang("ja");
     string out("foo.conf");
 
@@ -101,7 +101,7 @@
       }
     */
     printf("\n\n*** remove\n");
-    mod = "/usr/lib/im/leif/CannaLE.so";
+    mod = IM_DIRECTORY "/leif/CannaLE.so";
     xml.removemodule(mod, lang);
     /*
       for (IMModuleInfoVec::iterator i = lev->begin (); i != lev->end (); i++) {
