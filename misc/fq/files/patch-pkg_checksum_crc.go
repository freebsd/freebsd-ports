--- pkg/checksum/crc.go.orig	2021-12-20 16:21:07 UTC
+++ pkg/checksum/crc.go
@@ -8,7 +8,7 @@ import (
 
 type Table [256]uint
 
-func MakeTable(poly int, bits int) Table {
+func MakeTable(poly uint, bits int) Table {
 	table := [256]uint{}
 	mask := uint((1 << bits) - 1)
 
@@ -17,7 +17,7 @@ func MakeTable(poly int, bits int) Table {
 		crc := uint(i << (bits - 8))
 		for j := 0; j < 8; j++ {
 			if crc&(1<<(bits-1)) != 0 {
-				crc = ((crc << 1) ^ uint(poly)) & mask
+				crc = ((crc << 1) ^ poly) & mask
 			} else {
 				crc = (crc << 1) & mask
 			}
