--- syncthing/lib/api/api_test.go.orig	2020-08-11 08:56:46 UTC
+++ syncthing/lib/api/api_test.go
@@ -1136,7 +1136,7 @@ func TestPrefixMatch(t *testing.T) {
 	}
 }
 
-func TestCheckExpiry(t *testing.T) {
+func TestShouldRegenerateCertificate(t *testing.T) {
 	dir, err := ioutil.TempDir("", "syncthing-test")
 	if err != nil {
 		t.Fatal(err)
@@ -1149,7 +1149,7 @@ func TestCheckExpiry(t *testing.T) {
 	if err != nil {
 		t.Fatal(err)
 	}
-	if err := checkExpiry(crt); err == nil {
+	if err := shouldRegenerateCertificate(crt); err == nil {
 		t.Error("expected expiry error")
 	}
 
@@ -1158,7 +1158,7 @@ func TestCheckExpiry(t *testing.T) {
 	if err != nil {
 		t.Fatal(err)
 	}
-	if err := checkExpiry(crt); err != nil {
+	if err := shouldRegenerateCertificate(crt); err != nil {
 		t.Error("expected no error:", err)
 	}
 
@@ -1168,7 +1168,7 @@ func TestCheckExpiry(t *testing.T) {
 		if err != nil {
 			t.Fatal(err)
 		}
-		if err := checkExpiry(crt); err == nil {
+		if err := shouldRegenerateCertificate(crt); err == nil {
 			t.Error("expected expiry error")
 		}
 	}
