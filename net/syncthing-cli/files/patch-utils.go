--- utils.go
+++ utils.go
@@ -146,7 +146,7 @@ func validAddress(input string) {
 	if len(tokens) != 2 {
 		die(input + " is not a valid value for an address\nExpected format <ip or hostname>:<port>")
 	}
-	matched, err := regexp.MatchString("^[a-zA-Z0-9]+([a-zA-Z0-9.]+[a-zA-Z0-9]+)?$", tokens[0])
+	matched, err := regexp.MatchString("^[a-zA-Z0-9]+([-a-zA-Z0-9.]+[-a-zA-Z0-9]+)?$", tokens[0])
 	die(err)
 	if !matched {
 		die(input + " is not a valid value for an address\nExpected format <ip or hostname>:<port>")
