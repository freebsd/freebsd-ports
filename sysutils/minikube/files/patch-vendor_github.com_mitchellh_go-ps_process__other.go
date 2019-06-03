Obtained from https://github.com/mjarkk/go-ps/blob/master/process_other.go
This methods are used just by the package drivers/hyperkit, which is not used in FreeBSD.

--- vendor/github.com/mitchellh/go-ps/process_other.go.orig	2019-06-03 21:13:11 UTC
+++ vendor/github.com/mitchellh/go-ps/process_other.go
@@ -0,0 +1,20 @@
+// +build netbsd,arm openbsd,amd64 openbsd,386 freebsd,386 netbsd,amd64 freebsd,arm netbsd,386
+
+package ps
+
+import "errors"
+
+// processes is a fallback function the real functions are in the files spesific to an OS and platform
+func processes() ([]Process, error) {
+	return []Process{}, errors.New("OS or Platform not supported")
+}
+
+// findProcess is a fallback function the real functions are in the files spesific to an OS
+func findProcess(pid int) (Process, error) {
+	return nil, errors.New("OS or Platform not supported")
+}
+
+// supports returns false because of the fallback functions above
+func supported() bool {
+	return false
+}
