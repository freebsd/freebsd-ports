Remove the missing accel_flags field to prevent build failure.

XXX: Investigate this further.

--- vendor/github.com/gotk3/gotk3/gtk/accel.go.orig	2021-04-07 12:07:51 UTC
+++ vendor/github.com/gotk3/gotk3/gtk/accel.go
@@ -244,7 +244,6 @@ func (v *AccelKey) native() *C.struct__GtkAccelKey {
 	var val C.struct__GtkAccelKey
 	val.accel_key = C.guint(v.key)
 	val.accel_mods = C.GdkModifierType(v.mods)
-	val.accel_flags = v.flags
 	return &val
 }
 
@@ -253,7 +252,6 @@ func wrapAccelKey(obj *C.struct__GtkAccelKey) *AccelKe
 
 	v.key = uint(obj.accel_key)
 	v.mods = gdk.ModifierType(obj.accel_mods)
-	v.flags = uint16(obj.accel_flags)
 
 	return &v
 }
