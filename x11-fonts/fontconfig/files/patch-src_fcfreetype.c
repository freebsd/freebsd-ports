--- src/fcfreetype.c	2003/04/16 18:08:47	1.23
+++ src/fcfreetype.c	2003/04/18 15:56:05	1.25
@@ -55,9 +55,15 @@
 #include <freetype/ttnameid.h>
 #include <freetype/t1tables.h>
 
-#if (FREETYPE_MINOR > 1 || (FREETYPE_MINOR == 1 && FREETYPE_PATCH >= 3))
+#if (FREETYPE_MINOR > 1 || (FREETYPE_MINOR == 1 && FREETYPE_PATCH >= 4))
 #include <freetype/ftbdf.h>
+#include <freetype/ftmodule.h>
 #define USE_FTBDF
+#define HAS_BDF_PROPERTY(f) ((f) && (f)->driver && \
+			     (f)->driver->root.clazz->get_interface)
+#define MY_Get_BDF_Property(f,n,p) (HAS_BDF_PROPERTY(f) ? \
+				    FT_Get_BDF_Property(f,n,p) : \
+				    FT_Err_Invalid_Argument)
 #endif
 
 
@@ -781,7 +787,7 @@
     {
 	int             rc;
 	BDF_PropertyRec prop;
-	rc = FT_Get_BDF_Property(face, "FOUNDRY", &prop);
+	rc = MY_Get_BDF_Property(face, "FOUNDRY", &prop);
 	if(rc == 0 && prop.type == BDF_PROPERTY_TYPE_ATOM)
 	    foundry = prop.u.atom;
     }
@@ -789,7 +795,7 @@
     if (width == -1)
     {
 	BDF_PropertyRec prop;
-	if (FT_Get_BDF_Property(face, "RELATIVE_SETWIDTH", &prop) == 0 &&
+	if (MY_Get_BDF_Property(face, "RELATIVE_SETWIDTH", &prop) == 0 &&
 	    (prop.type == BDF_PROPERTY_TYPE_INTEGER ||
 	     prop.type == BDF_PROPERTY_TYPE_CARDINAL))
 	{
@@ -811,7 +817,7 @@
 	    case 9: width = FC_WIDTH_ULTRAEXPANDED; break;
 	    }
 	}
-	else if (FT_Get_BDF_Property (face, "SETWIDTH_NAME", &prop) == 0 &&
+	else if (MY_Get_BDF_Property (face, "SETWIDTH_NAME", &prop) == 0 &&
 		 prop.type == BDF_PROPERTY_TYPE_ATOM)
 	{
 	    static struct {
