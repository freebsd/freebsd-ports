--- pkg/collector/hydratation/hydration.go.orig	2024-02-12 15:25:23 UTC
+++ pkg/collector/hydratation/hydration.go
@@ -56,7 +56,7 @@ func fill(field reflect.Value) error {
 	case reflect.Int64:
 		switch field.Type() {
 		case reflect.TypeOf(types.Duration(time.Second)):
-			setTyped(field, int64(defaultNumber*int(time.Second)))
+			setTyped(field, int64(defaultNumber)*int64(time.Second))
 		default:
 			setTyped(field, int64(defaultNumber))
 		}
