--- inti/glib/property.h.orig	Sat Sep 18 21:03:00 2004
+++ inti/glib/property.h	Sat Sep 18 21:04:01 2004
@@ -187,12 +187,12 @@
 
 	void get(DataType& data) const
 	{
-		property()->get(object(), data);
+		this->property()->get(this->object(), data);
 	}
 
 	void set(const DataType& data) const
 	{
-		property()->set(object(), data);
+		this->property()->set(this->object(), data);
 	}
 };
 
