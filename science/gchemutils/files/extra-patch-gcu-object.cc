--- gcu/object.cc.orig	Thu Mar 17 14:45:35 2005
+++ gcu/object.cc	Sat Apr  2 23:05:36 2005
@@ -392,7 +392,13 @@
 		while (max > TypeNames.size())
 			TypeNames.push_back ("");
 	}
+	/*
 	TypeNames.at (typedesc.Id) = TypeName;
+	 */
+	vector<string>::iterator bleh;
+	bleh = TypeNames.begin();
+	bleh += typedesc.Id;
+	TypeNames.insert(bleh, TypeName);
 	return typedesc.Id;
 }
 
