--- leif/sampleja3/sampleja3.c	Mon Apr 26 21:16:13 2004
+++ leif/sampleja3/sampleja3.c	Wed Feb 16 20:42:52 2005
@@ -171,7 +171,7 @@
 		objects[obj_id].name_length = 9;
 		objects[obj_id].domain = "com.sun";
 		objects[obj_id].scope = "sampleja3";
-		objects[obj_id].path = "/usr/lib/im/locale/ja/sampleja3/aux.jar";
+		objects[obj_id].path = IMDIR "/locale/ja/sampleja3/aux.jar";
 		objects[obj_id].signature = "";
 		objects[obj_id].class_names = class_names;
 		objects[obj_id].count_names = 1;
