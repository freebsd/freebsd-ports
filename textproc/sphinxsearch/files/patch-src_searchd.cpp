--- src/searchd.cpp.orig	2018-02-03 10:33:59 UTC
+++ src/searchd.cpp
@@ -8580,16 +8580,16 @@ struct GenericMatchSort_fn : public CSphMatchComparato
 
 			case SPH_KEYPART_INT:
 			{
-				register SphAttr_t aa = a->GetAttr ( m_tLocator[i] );
-				register SphAttr_t bb = b->GetAttr ( m_tLocator[i] );
+				SphAttr_t aa = a->GetAttr ( m_tLocator[i] );
+				SphAttr_t bb = b->GetAttr ( m_tLocator[i] );
 				if ( aa==bb )
 					continue;
 				return ( ( m_uAttrDesc>>i ) & 1 ) ^ ( aa < bb );
 			}
 			case SPH_KEYPART_FLOAT:
 			{
-				register float aa = a->GetAttrFloat ( m_tLocator[i] );
-				register float bb = b->GetAttrFloat ( m_tLocator[i] );
+				float aa = a->GetAttrFloat ( m_tLocator[i] );
+				float bb = b->GetAttrFloat ( m_tLocator[i] );
 				if ( aa==bb )
 					continue;
 				return ( ( m_uAttrDesc>>i ) & 1 ) ^ ( aa < bb );
