--- src/contribs-lib/CLucene/highlighter/WeightedTerm.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/contribs-lib/CLucene/highlighter/WeightedTerm.cpp	2013-03-27 16:51:33.000000000 -0400
@@ -73,7 +73,7 @@
 	 * @param weight the weight associated with this term
 	 */
 	void WeightedTerm::setWeight(float_t weight) {
-		this->_weight = _weight;
+		_weight = weight;
 		cachedHashCode = 0;
 	}
 
