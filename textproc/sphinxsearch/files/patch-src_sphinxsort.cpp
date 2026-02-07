--- src/sphinxsort.cpp.orig	2018-02-03 10:36:00 UTC
+++ src/sphinxsort.cpp
@@ -3395,15 +3395,15 @@ struct MatchExpr_fn : public ISphMatchComparator
 		case SPH_KEYPART_WEIGHT:	SPH_TEST_PAIR ( a.m_iWeight, b.m_iWeight, _idx ); break; \
 		case SPH_KEYPART_INT: \
 		{ \
-			register SphAttr_t aa = a.GetAttr ( t.m_tLocator[_idx] ); \
-			register SphAttr_t bb = b.GetAttr ( t.m_tLocator[_idx] ); \
+			SphAttr_t aa = a.GetAttr ( t.m_tLocator[_idx] ); \
+			SphAttr_t bb = b.GetAttr ( t.m_tLocator[_idx] ); \
 			SPH_TEST_PAIR ( aa, bb, _idx ); \
 			break; \
 		} \
 		case SPH_KEYPART_FLOAT: \
 		{ \
-			register float aa = a.GetAttrFloat ( t.m_tLocator[_idx] ); \
-			register float bb = b.GetAttrFloat ( t.m_tLocator[_idx] ); \
+			float aa = a.GetAttrFloat ( t.m_tLocator[_idx] ); \
+			float bb = b.GetAttrFloat ( t.m_tLocator[_idx] ); \
 			SPH_TEST_PAIR ( aa, bb, _idx ) \
 			break; \
 		} \
