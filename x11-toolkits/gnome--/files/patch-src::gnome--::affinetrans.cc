
$FreeBSD$

--- src/gnome--/affinetrans.cc	2002/07/16 10:11:14	1.1
+++ src/gnome--/affinetrans.cc	2002/07/16 10:13:14
@@ -29,7 +29,7 @@
 namespace Art
 {
 
-AffineTrans::AffineTrans(gdouble scale = 1.0)
+AffineTrans::AffineTrans(gdouble scale)
 {
   trans_[0] = scale;
   trans_[1] = 0.0;
