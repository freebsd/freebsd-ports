--- libsi/si.c.orig
+++ libsi/si.c
@@ -308,6 +308,25 @@ static const char *CharacterTables2[] = 
   "ISO-8859-15", // 0x0F
 };
 
+static const char *CharacterTables3[] = {
+  NULL,          // 0x00
+  "ISO8859-1",  // 0x01
+  "ISO8859-2",  // 0x02
+  "ISO8859-3",  // 0x03
+  "ISO8859-4",  // 0x04
+  "ISO8859-5",  // 0x05
+  "ISO8859-6",  // 0x06
+  "ISO8859-7",  // 0x07
+  "ISO8859-8",  // 0x08
+  "ISO8859-9",  // 0x09
+  "ISO8859-10", // 0x0A
+  "ISO8859-11", // 0x0B
+  "ISO8859-12", // 0x0C
+  "ISO8859-13", // 0x0D
+  "ISO8859-14", // 0x0E
+  "ISO8859-15", // 0x0F
+};
+
 #define NumEntries(Table) (sizeof(Table) / sizeof(char *))
 
 static const char *SystemCharacterTable = NULL;
@@ -334,6 +353,13 @@ bool SetSystemCharacterTable(const char 
             return true;
          }
       }
+      for (unsigned int i = 0; i < NumEntries(CharacterTables3); i++) {
+         if (CharacterTables3[i] && strcasecmp(CharacterTable, CharacterTables3[i]) == 0) {
+            SystemCharacterTable = CharacterTables3[i];
+            SystemCharacterTableIsSingleByte = true;
+            return true;
+         }
+      }
    } else {
       SystemCharacterTable = NULL;
       SystemCharacterTableIsSingleByte = true;
