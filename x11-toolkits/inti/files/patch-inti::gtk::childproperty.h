--- inti/gtk/childproperty.h.orig	Sat Sep 18 21:10:17 2004
+++ inti/gtk/childproperty.h	Sat Sep 18 21:12:44 2004
@@ -139,12 +139,12 @@
 
 	void get(const Widget& child, DataType& data) const
 	{
-		property()->get(object(), child, data);
+		this->property()->get(this->object(), child, data);
 	}
 
 	void set(Widget& child, const DataType& data) const
 	{
-		property()->set(object(), child, data);
+		this->property()->set(this->object(), child, data);
 	}
 };
 
