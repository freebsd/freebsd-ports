--- src/polynomial.h.orig	Tue Feb 12 05:56:44 2002
+++ src/polynomial.h	Fri Oct 25 15:56:13 2002
@@ -16,7 +16,7 @@
 	class PolynomialRep
 	{
 	public:
-		vector<int> data;
+		std::vector<int> data;
 		unsigned int ref;
 
 		PolynomialRep ();
@@ -52,7 +52,7 @@
 	int operator() (int x) const;
 	Polynomial &operator= (const Polynomial &other);
 
-	friend ostream &operator<< (ostream &o, const Polynomial &p);
+	friend std::ostream &operator<< (std::ostream &o, const Polynomial &p);
 	friend bool operator== (const Polynomial &p1,
 						const Polynomial &p2);
 	void operator+= (const Polynomial &other);
