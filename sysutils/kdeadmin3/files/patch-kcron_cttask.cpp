--- kcron/cttask.cpp	2003/03/31 12:18:41	1.14
+++ kcron/cttask.cpp	2004/06/01 14:12:34	1.14.2.1
@@ -44,6 +44,39 @@ CTTask::CTTask(string tokStr, string _co
   {
     silent = false;
   }
+  
+  if (tokStr.substr(0,1) == "@")
+  {
+    if (tokStr.substr(1,6) == "reboot")
+    {
+      // Dunno what to do with this...
+      tokStr = "0 0 1 1 *"+tokStr.substr(7,tokStr.length()-1);
+    }
+    else if (tokStr.substr(1,6) == "yearly")
+    {
+      tokStr = "0 0 1 1 *"+tokStr.substr(7,tokStr.length()-1);
+    }
+    else if (tokStr.substr(1,8) == "annually")
+    {
+      tokStr = "0 0 1 1 *"+tokStr.substr(9,tokStr.length()-1);
+    }
+    else if (tokStr.substr(1,7) == "monthly")
+    {
+      tokStr = "0 0 1 * *"+tokStr.substr(8,tokStr.length()-1);
+    }
+    else if (tokStr.substr(1,6) == "weekly")
+    {
+      tokStr = "0 0 * * 0"+tokStr.substr(7,tokStr.length()-1);
+    }
+    else if (tokStr.substr(1,5) == "daily")
+    {
+      tokStr = "0 0 * * *"+tokStr.substr(6,tokStr.length()-1);
+    }
+    else if (tokStr.substr(1,6) == "hourly")
+    {
+      tokStr = "0 * * * *"+tokStr.substr(7,tokStr.length()-1);
+    }
+  }
 
   int spacepos(tokStr.find_first_of(" \t"));
   minute.initialize(tokStr.substr(0,spacepos));
