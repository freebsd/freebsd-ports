--- src/registry.hxx.orig	Sun Dec 15 09:13:27 2002
+++ src/registry.hxx	Sun Dec 15 09:12:51 2002
@@ -89,7 +89,7 @@
   void LoadFromFile(const STRING& FileName);
   void AddFromFile(const STRING& FileName);
 //  void Print(ostream& os, const INT Level) const;
-	void fprint(FILE* fp, const INT level = 0) const;
+	void fprint(FILE* fp, const INT level) const;
   void ProfilePrint(ostream& os, const INT Level) const;
   void GetData(STRLIST *StrlistBuffer);
   void DeleteChildren();
