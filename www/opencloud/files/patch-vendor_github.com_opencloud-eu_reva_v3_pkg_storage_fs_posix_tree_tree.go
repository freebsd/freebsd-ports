--- vendor/github.com/opencloud-eu/reva/v3/pkg/storage/fs/posix/tree/tree.go.orig	2026-11-17 12:00:00 UTC
+++ vendor/github.com/opencloud-eu/reva/v3/pkg/storage/fs/posix/tree/tree.go
@@ -287,7 +287,7 @@ func (t *Tree) checkStorage() error {
 		}
 	}()
 
-	attrKey := "user.posixfs.test"
+	attrKey := prefixes.OcPrefix + "posixfs.test"
 	attrVal := []byte("test")
 	if err := xattr.Set(f.Name(), attrKey, attrVal); err != nil {
 		return errors.Wrap(err, "extended attributes not supported")
