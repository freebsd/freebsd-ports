--- vendor/github.com/flashmob/go-guerrilla/guerrilla_unix.go.orig	2020-09-05 09:53:49 UTC
+++ vendor/github.com/flashmob/go-guerrilla/guerrilla_unix.go
@@ -11,5 +11,5 @@ func getFileLimit() (uint64, error) {
 	if err != nil {
 		return 0, err
 	}
-	return rLimit.Max, nil
+	return uint64(rLimit.Max), nil
 }
