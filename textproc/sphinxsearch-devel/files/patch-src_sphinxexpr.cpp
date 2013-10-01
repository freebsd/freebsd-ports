--- src/sphinxexpr.cpp.orig	2011-03-11 17:43:11.000000000 +0000
+++ src/sphinxexpr.cpp
@@ -1722,7 +1722,7 @@ public:
 	/// evaluate arg, return interval id
 	virtual int IntEval ( const CSphMatch & tMatch ) const
 	{
-		T val = ExprEval ( this->m_pArg, tMatch ); // 'this' fixes gcc braindamage
+		T val = this->ExprEval ( this->m_pArg, tMatch ); // 'this' fixes gcc braindamage
 		ARRAY_FOREACH ( i, this->m_dValues ) // FIXME! OPTIMIZE! perform binary search here
 			if ( val<this->m_dValues[i] )
 				return i;
@@ -1753,7 +1753,7 @@ public:
 	/// evaluate arg, return interval id
 	virtual int IntEval ( const CSphMatch & tMatch ) const
 	{
-		T val = ExprEval ( this->m_pArg, tMatch ); // 'this' fixes gcc braindamage
+		T val = this->ExprEval ( this->m_pArg, tMatch ); // 'this' fixes gcc braindamage
 		ARRAY_FOREACH ( i, m_dTurnPoints )
 			if ( val < Expr_ArgVsSet_c<T>::ExprEval ( m_dTurnPoints[i], tMatch ) )
 				return i;
@@ -1799,7 +1799,7 @@ public:
 	/// evaluate arg, check if the value is within set
 	virtual int IntEval ( const CSphMatch & tMatch ) const
 	{
-		T val = ExprEval ( this->m_pArg, tMatch ); // 'this' fixes gcc braindamage
+		T val = this->ExprEval ( this->m_pArg, tMatch ); // 'this' fixes gcc braindamage
 		return this->m_dValues.BinarySearch ( val )!=NULL;
 	}
 
