--- src/polynomial.cc.orig	Fri Oct 25 16:00:00 2002
+++ src/polynomial.cc	Fri Oct 25 16:01:50 2002
@@ -23,7 +23,7 @@
 
 void Polynomial::minimise ()
 {
-	vector<int>::iterator it;
+	std::vector<int>::iterator it;
 
 	for (it = rep->data.end () - 1; it != rep->data.begin (); --it)
 		if (*it)
@@ -142,7 +142,7 @@
 
 int Polynomial::eval (int x) const
 {
-	vector<int>::reverse_iterator it;
+	std::vector<int>::reverse_iterator it;
 	int val;
 
 	val = 0;
@@ -200,7 +200,7 @@
 
 std::ostream &operator<< (std::ostream &o, const Polynomial &p)
 {
-	vector<int>::reverse_iterator it;
+	std::vector<int>::reverse_iterator it;
 	int pow, val;
 	bool sp;
 
