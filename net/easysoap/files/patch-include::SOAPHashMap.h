--- include/easysoap/SOAPHashMap.h.orig	Thu Jun 26 09:58:31 2003
+++ include/easysoap/SOAPHashMap.h	Thu Jun 26 10:05:23 2003
@@ -117,13 +117,13 @@
 	{
 	private:
 		const SOAPHashMap		*m_map;
-		Elements::Iterator		m_index;
+		typename Elements::Iterator		m_index;
 		HashElement				*m_he;
 		
 		friend class SOAPHashMap<K,I,H,E>;
 
 		// private constuctor that can only be called by SOAPHashMap
-		ForwardHashMapIterator(const SOAPHashMap *map, Elements::Iterator index)
+		ForwardHashMapIterator(const SOAPHashMap *map, typename Elements::Iterator index)
 			: m_map(map), m_index(index), m_he(0)
 		{
 			if (m_map)
@@ -134,7 +134,7 @@
 			}
 		}
 
-		ForwardHashMapIterator(const SOAPHashMap *map, Elements::Iterator index, HashElement *he)
+		ForwardHashMapIterator(const SOAPHashMap *map, typename Elements::Iterator index, HashElement *he)
 			: m_map(map), m_index(index), m_he(he)
 		{
 		}
@@ -366,8 +366,8 @@
 		{
 			Clear();
 			Resize(r.GetNumBuckets());
-			SOAPHashMap<A,B,C,D>::Iterator e = r.End();
-			for (SOAPHashMap<A,B,C,D>::Iterator it = r.Begin(); it != e; ++it)
+			typename SOAPHashMap<A,B,C,D>::Iterator e = r.End();
+			for (typename SOAPHashMap<A,B,C,D>::Iterator it = r.Begin(); it != e; ++it)
 				Add(it.Key(), it.Item());
 		}
 		return *this;
@@ -397,7 +397,7 @@
 	 */
 	Iterator Begin() const
 	{
-		return Iterator(this, (Elements::Iterator)m_elements.Begin());
+		return Iterator(this, (typename Elements::Iterator)m_elements.Begin());
 	}
 
 	/**
@@ -407,7 +407,7 @@
 	 */
 	Iterator End() const
 	{
-		return Iterator(this, (Elements::Iterator)m_elements.End());
+		return Iterator(this, (typename Elements::Iterator)m_elements.End());
 	}
 
 
@@ -491,7 +491,7 @@
 	 */
 	void Clear()
 	{
-		for (Elements::Iterator i = m_elements.Begin(); i != m_elements.End(); ++i)
+		for (typename Elements::Iterator i = m_elements.Begin(); i != m_elements.End(); ++i)
 		{
 			HashElement *he = *i;
 			while (he)
@@ -512,7 +512,7 @@
 	 */
 	void Empty()
 	{
-		Elements::Iterator i;
+		typename Elements::Iterator i;
 		for (i = m_elements.Begin(); i != m_elements.End(); ++i)
 		{
 			HashElement *he = *i;
@@ -588,7 +588,7 @@
 			while (he)
 			{
 				if (he->m_hash == hash && equals(he->m_key, key))
-					return Iterator(this, (Elements::Iterator)m_elements.Begin() + index, he);
+					return Iterator(this, (typename Elements::Iterator)m_elements.Begin() + index, he);
 				he = he->m_next;
 			}
 		}
@@ -603,7 +603,7 @@
 
 		Elements newelements;
 		newelements.Resize(newsize);
-		Elements::Iterator i;
+		typename Elements::Iterator i;
 
 		for (i = newelements.Begin(); i != newelements.End(); ++i)
 			*i = 0;
