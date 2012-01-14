--- uhidd/uhidd_hidump.c~
+++ uhidd/uhidd_hidump.c
@@ -296,7 +296,7 @@ get_unit(int dval, unsigned int sz)
 
 normal:
 	for (i = 1; (unsigned int)i < sz * 2; i++) {
-		nibble = (dval >> (i * 4)) && 0x0F;
+		nibble = (dval >> (i * 4)) & 0x0F;
 		if (!nibble)
 			continue;
 		if (nibble > 7)
