--- src/graphics/objects.h~	Sat Dec 29 23:56:49 2001
+++ src/graphics/objects.h	Sun Jan 30 16:05:29 2005
@@ -88,8 +88,6 @@
 	void SetModelView(void) const;
 	const obj_loc_data * GetLocData(void) const;
 	
-	protected:
-	
 	obj_loc_data * GetLocDataRW(void) const;
 	
 	public:
