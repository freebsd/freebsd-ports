--- vendor/github.com/elastic/gosigar/sigar_freebsd.go.orig	2018-08-05 17:40:01 UTC
+++ vendor/github.com/elastic/gosigar/sigar_freebsd.go
@@ -4,6 +4,7 @@ package gosigar
 
 import (
 	"io/ioutil"
+	"runtime"
 	"strconv"
 	"strings"
 	"unsafe"
