-- Fix non-constant format string errors in FreeBSD temperature code.
-- Go 1.24 vet treats dynamic strings passed to log.Printf as format strings
-- as a compile-time error. Use "%s" as the constant format and pass the
-- translated string as the argument.
-- Upstream issue: not yet reported.

--- devices/temp_freebsd.go.orig	2026-11-11 18:36:52 UTC
+++ devices/temp_freebsd.go
@@ -58,7 +58,7 @@ func devs() []string {
 	// Check that thermal sensors are really available; they aren't in VMs
 	bs, err := exec.Command("sysctl", "-a").Output()
 	if err != nil {
-		log.Printf(tr.Value("error.fatalfetch", "temp", err.Error()))
+		log.Printf("%s", tr.Value("error.fatalfetch", "temp", err.Error()))
 		return []string{}
 	}
 	for k, _ := range sensorOIDS {
@@ -72,7 +72,7 @@ func devs() []string {
 		for k, _ := range sensorOIDS {
 			oids = append(oids, k)
 		}
-		log.Printf(tr.Value("error.nodevfound", strings.Join(oids, ", ")))
+		log.Printf("%s", tr.Value("error.nodevfound", strings.Join(oids, ", ")))
 	}
 	return rv
 }
