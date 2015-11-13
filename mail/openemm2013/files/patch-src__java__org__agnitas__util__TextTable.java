--- src/java/org/agnitas/util/TextTable.java.orig	2015-10-11 16:41:55 UTC
+++ src/java/org/agnitas/util/TextTable.java
@@ -98,7 +98,7 @@ public class TextTable {
 	
 	public void setAlignmentForColumn(int columnIndex, boolean alignRight) throws Exception {
 		if (columnIndex < 0 || columnIndex >= columnNames.get(0).size())
-			throw new Exception("Ungültige Spalten-Indexangabe: " + columnIndex);
+			throw new Exception("Ung\u00FCltige Spalten-Indexangabe: " + columnIndex);
 		
 		columnRightAligned.set(columnIndex, alignRight);
 	}
@@ -482,7 +482,7 @@ public class TextTable {
 	
 	public String getHeader(int headerLineIndex, int columnIndex) throws Exception {
 		if (columnNames.size() <= headerLineIndex || columnNames.get(headerLineIndex).size() <= columnIndex)
-			throw new Exception("Ungültige Datenabfrage an Spaltenüberschriften Zeilenindex " + headerLineIndex + " Spaltenindex " + columnIndex);
+			throw new Exception("Ung\u00FCltige Datenabfrage an Spalten\u00FCberschriften Zeilenindex " + headerLineIndex + " Spaltenindex " + columnIndex);
 		return columnNames.get(headerLineIndex).get(columnIndex);
 	}
 	
@@ -496,7 +496,7 @@ public class TextTable {
 	
 	public String getData(int lineIndex, int columnIndex) throws Exception {
 		if (content.size() <= lineIndex || content.get(lineIndex).size() <= columnIndex)
-			throw new Exception("Ungültige Datenabfrage an Zeilenindex " + lineIndex + " Spaltenindex " + columnIndex);
+			throw new Exception("Ung\u00FCltige Datenabfrage an Zeilenindex " + lineIndex + " Spaltenindex " + columnIndex);
 		return content.get(lineIndex).get(columnIndex);
 	}
 
