--- /dev/null	2023-03-29 16:51:35 UTC
+++ vendor/github.com/boltdb/bolt/bolt_riscv64.go
@@ -0,0 +1,13 @@
+//go:build riscv64
+// +build riscv64
+
+package bolt
+
+// maxMapSize represents the largest mmap size supported by Bolt.
+const maxMapSize = 0xFFFFFFFFFFFF // 256TB
+
+// maxAllocSize is the size used when creating array pointers.
+const maxAllocSize = 0x7FFFFFFF
+
+// are unaligned reads/writes not supported?
+var brokenUnaligned = false
