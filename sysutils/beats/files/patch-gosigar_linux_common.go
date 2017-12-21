--- vendor/github.com/elastic/gosigar/sigar_linux_common.go.orig	2017-12-21 14:43:33.660692000 +0100
+++ vendor/github.com/elastic/gosigar/sigar_linux_common.go	2017-12-21 14:44:02.666180000 +0100
@@ -274,6 +274,7 @@
 	return nil
 }
 
+/*
 func (self *ProcTime) Get(pid int) error {
 	contents, err := readProcFile(pid, "stat")
 	if err != nil {
@@ -297,6 +298,7 @@
 
 	return nil
 }
+*/
 
 func (self *ProcArgs) Get(pid int) error {
 	contents, err := readProcFile(pid, "cmdline")
