--- src/opstack.hxx.orig	1996-12-21 00:41:10.000000000 +0000
+++ src/opstack.hxx	2007-12-01 16:38:59.000000000 +0000
@@ -57,7 +57,7 @@ public:
 	OPSTACK& operator<<(OPOBJ* Op);
 	POPOBJ operator>>(POPOBJ& OpPtr);
  	PIRSET operator>>(PIRSET& OpPtr);
-	void OPSTACK::Reverse();
+	void Reverse();
 	~OPSTACK();
 private:
 	void Push(OPOBJ& Op);
