commit 988370a873665ea56d5cf1c287c7274f88c429a3
Author: Palle Girgensohn <girgen@pingpong.net>
Date:   Thu Dec 28 11:55:29 2017 +0100

    Use the common version of Get(pid)

diff --git a/sigar_freebsd.go b/sigar_freebsd.go
index 0a31d08..602b4a0 100644
--- a/sigar_freebsd.go
+++ vendor/github.com/elastic/gosigar/sigar_freebsd.go
@@ -4,7 +4,6 @@ package gosigar
 
 import (
 	"io/ioutil"
-	"runtime"
 	"strconv"
 	"strings"
 	"unsafe"
@@ -107,7 +106,3 @@ func parseCpuStat(self *Cpu, line string) error {
 	self.Idle, _ = strtoull(fields[4])
 	return nil
 }
-
-func (self *ProcTime) Get(pid int) error {
-	return ErrNotImplemented{runtime.GOOS}
-}
