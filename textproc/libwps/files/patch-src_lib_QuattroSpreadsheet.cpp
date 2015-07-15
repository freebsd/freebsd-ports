--- src/lib/QuattroSpreadsheet.cpp.orig	2015-03-11 11:14:10 UTC
+++ src/lib/QuattroSpreadsheet.cpp
@@ -1668,7 +1668,7 @@ bool QuattroSpreadsheet::readCell
 			else
 			{
 				val &= 0x3FFF;
-				if (val & 0x2000) val = val - 0x4000;
+				if (val>0x1000) val = val - 0x2000;
 			}
 			if (dim==2)
 				val += sheetId;
