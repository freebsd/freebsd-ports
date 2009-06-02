
$FreeBSD$

--- components/foxyproxy.js.orig
+++ components/foxyproxy.js
@@ -424,15 +424,13 @@
   },
 
   getDefaultPath : function() {
-    //var file = CC["@mozilla.org/file/local;1"].createInstance(CI.nsILocalFile);
-    //var dir = CC["@mozilla.org/file/directory_service;1"].getService(CI.nsIProperties).get("ProfD", CI.nsILocalFile);
-    var f = settingsDir.clone();
-    f.append("foxyproxy.xml");
+    var file = CC["@mozilla.org/file/local;1"].createInstance(CI.nsILocalFile);
+    var dir = CC["@mozilla.org/file/directory_service;1"].getService(CI.nsIProperties).get("ProfD", CI.nsILocalFile);
     // dump("settings file: " + f.path + "\n");
     return f;
-    // file.initWithPath(dir.path);
-    // file.appendRelativePath("foxyproxy.xml");
-    // return file;
+    file.initWithPath(dir.path);
+    file.appendRelativePath("foxyproxy.xml");
+    return file;
   },
 
   // Convert |o| from:
