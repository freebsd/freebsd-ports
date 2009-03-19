
$FreeBSD$

--- components/foxyproxy.js.orig
+++ components/foxyproxy.js
@@ -430,15 +430,12 @@
   },
 
   getDefaultPath : function() {
-    //var file = CC["@mozilla.org/file/local;1"].createInstance(CI.nsILocalFile);
-    //var dir = CC["@mozilla.org/file/directory_service;1"].getService(CI.nsIProperties).get("ProfD", CI.nsILocalFile);
-    var f = settingsDir.clone();
-    f.append("foxyproxy.xml");
+    var file = CC["@mozilla.org/file/local;1"].createInstance(CI.nsILocalFile);
+    var dir = CC["@mozilla.org/file/directory_service;1"].getService(CI.nsIProperties).get("ProfD", CI.nsILocalFile);
     //dump("settings file: " + f.path + "\n");
-    return f;
-    //file.initWithPath(dir.path);
-    //file.appendRelativePath("foxyproxy.xml");
-    //return file;
+    file.initWithPath(dir.path);
+    file.appendRelativePath("foxyproxy.xml");
+    return file;
   },
 
   // Convert |o| from:
@@ -1471,4 +1468,4 @@
   _xpComObjects: {},
   _catObserverName: null,
   _catContractId: null
-};
\ No newline at end of file
+};
