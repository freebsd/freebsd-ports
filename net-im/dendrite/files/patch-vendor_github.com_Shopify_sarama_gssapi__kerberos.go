--- vendor/github.com/Shopify/sarama/gssapi_kerberos.go.orig	2021-05-07 12:35:44 UTC
+++ vendor/github.com/Shopify/sarama/gssapi_kerberos.go
@@ -59,8 +59,8 @@ type KerberosClient interface {
 func (krbAuth *GSSAPIKerberosAuth) writePackage(broker *Broker, payload []byte) (int, error) {
 	length := len(payload)
 	size := length + 4 // 4 byte length header + payload
-	if size > math.MaxUint32 {
-		return 0, errors.New("payload too large, will overflow uint32")
+	if size > math.MaxInt32 {
+		return 0, errors.New("payload too large, will overflow int32")
 	}
 	finalPackage := make([]byte, size)
 	copy(finalPackage[4:], payload)
