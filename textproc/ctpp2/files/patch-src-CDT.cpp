--- src/CDT.cpp.orig	2012-11-10 19:38:03 UTC
+++ src/CDT.cpp
@@ -108,17 +108,17 @@ static const CDT oNonExistentCDT;
 //
 // Constructor
 //
-CDT::Iterator::Iterator(CDT::Map::iterator itIMap): itMap(itIMap) { ;; }
+CDTIterator::CDTIterator(CDT::Map::iterator itIMap): itMap(itIMap) { ;; }
 
 //
 // Copy constructor
 //
-CDT::Iterator::Iterator(const CDT::Iterator & oRhs): itMap(oRhs.itMap) { ;; }
+CDTIterator::CDTIterator(const CDTIterator & oRhs): itMap(oRhs.itMap) { ;; }
 
 //
 // Operator =
 //
-CDT::Iterator & CDT::Iterator::operator=(const CDT::Iterator & oRhs)
+CDTIterator & CDTIterator::operator=(const CDTIterator & oRhs)
 {
 	if (this != &oRhs) { itMap = oRhs.itMap; }
 
@@ -128,7 +128,7 @@ CDT::Iterator & CDT::Iterator::operator=(const CDT::It
 //
 // Pre-increment operator ++
 //
-CDT::Iterator & CDT::Iterator::operator++()
+CDTIterator & CDTIterator::operator++()
 {
 	++itMap;
 
@@ -138,9 +138,9 @@ return *this;
 //
 // Post-increment operator ++
 //
-CDT::Iterator CDT::Iterator::operator++(int)
+CDTIterator CDTIterator::operator++(int)
 {
-	Iterator oTMP = *this;
+	CDTIterator oTMP = *this;
 
 	++itMap;
 
@@ -150,46 +150,46 @@ return oTMP;
 //
 // Access operator
 //
-STLW::pair<const STLW::string, CDT> * CDT::Iterator::operator->() { return &(*itMap); }
+STLW::pair<const STLW::string, CDT> * CDTIterator::operator->() { return &(*itMap); }
 
 //
 // Comparison operator
 //
-bool CDT::Iterator::operator ==(const CDT::Iterator & oRhs) { return (itMap == oRhs.itMap); }
+bool CDTIterator::operator ==(const CDTIterator & oRhs) { return (itMap == oRhs.itMap); }
 
 //
 // Comparison operator
 //
-bool CDT::Iterator::operator !=(const CDT::Iterator & oRhs) { return (itMap != oRhs.itMap); }
+bool CDTIterator::operator !=(const CDTIterator & oRhs) { return (itMap != oRhs.itMap); }
 
 //
 // Get iterator pointed to start of hash
 //
-CDT::Iterator CDT::Begin()
+CDTIterator CDT::Begin()
 {
 	if (eValueType != HASH_VAL) { throw CDTAccessException(); }
 
-return Iterator(u.p_data -> u.m_data -> begin());
+return CDTIterator(u.p_data -> u.m_data -> begin());
 }
 
 //
 // Get iterator pointed to end of hash
 //
-CDT::Iterator CDT::End()
+CDTIterator CDT::End()
 {
 	if (eValueType != HASH_VAL) { throw CDTAccessException(); }
 
-	return Iterator(u.p_data -> u.m_data -> end());
+	return CDTIterator(u.p_data -> u.m_data -> end());
 }
 
 //
 // Find element in hash
 //
-CDT::Iterator CDT::Find(const STLW::string & sKey)
+CDTIterator CDT::Find(const STLW::string & sKey)
 {
 	if (eValueType != HASH_VAL) { throw CDTAccessException(); }
 
-return Iterator(u.p_data -> u.m_data -> find(sKey));
+return CDTIterator(u.p_data -> u.m_data -> find(sKey));
 }
 
 // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -200,17 +200,17 @@ return Iterator(u.p_data -> u.m_data -> find(sKey));
 //
 // Copy constructor
 //
-CDT::ConstIterator::ConstIterator(const CDT::ConstIterator & oRhs): itMap(oRhs.itMap) { ;; }
+CDTConstIterator::CDTConstIterator(const CDTConstIterator & oRhs): itMap(oRhs.itMap) { ;; }
 
 //
 // Type cast constructor
 //
-CDT::ConstIterator::ConstIterator(const CDT::Iterator & oRhs): itMap(oRhs.itMap) { ;; }
+CDTConstIterator::CDTConstIterator(const CDTIterator & oRhs): itMap(oRhs.itMap) { ;; }
 
 //
 // Operator =
 //
-CDT::ConstIterator & CDT::ConstIterator::operator=(const ConstIterator & oRhs)
+CDTConstIterator & CDTConstIterator::operator=(const CDTConstIterator & oRhs)
 {
 	if (this != &oRhs) { itMap = oRhs.itMap; }
 
@@ -220,7 +220,7 @@ return *this;
 //
 // Operator =
 //
-CDT::ConstIterator & CDT::ConstIterator::operator=(const CDT::Iterator & oRhs)
+CDTConstIterator & CDTConstIterator::operator=(const CDTIterator & oRhs)
 {
 	itMap = oRhs.itMap;
 
@@ -230,7 +230,7 @@ return *this;
 //
 // Pre-increment operator ++
 //
-CDT::ConstIterator & CDT::ConstIterator::operator++()
+CDTConstIterator & CDTConstIterator::operator++()
 {
 	++itMap;
 
@@ -240,9 +240,9 @@ return *this;
 //
 // Post-increment operator ++
 //
-CDT::ConstIterator CDT::ConstIterator::operator++(int)
+CDTConstIterator CDTConstIterator::operator++(int)
 {
-	ConstIterator oTMP = *this;
+	CDTConstIterator oTMP = *this;
 
 	++itMap;
 
@@ -252,46 +252,46 @@ return oTMP;
 //
 // Access operator
 //
-const STLW::pair<const STLW::string, CDT> * CDT::ConstIterator::operator->() const { return &(*itMap); }
+const STLW::pair<const STLW::string, CDT> * CDTConstIterator::operator->() const { return &(*itMap); }
 
 //
 // Comparison operator
 //
-bool CDT::ConstIterator::operator ==(const CDT::ConstIterator & oRhs) const { return (itMap == oRhs.itMap); }
+bool CDTConstIterator::operator ==(const CDTConstIterator & oRhs) const { return (itMap == oRhs.itMap); }
 
 //
 // Comparison operator
 //
-bool CDT::ConstIterator::operator !=(const CDT::ConstIterator & oRhs) const { return (itMap != oRhs.itMap); }
+bool CDTConstIterator::operator !=(const CDTConstIterator & oRhs) const { return (itMap != oRhs.itMap); }
 
 //
 // Get constant iterator pointed to start of hash
 //
-CDT::ConstIterator CDT::Begin() const
+CDTConstIterator CDT::Begin() const
 {
 	if (eValueType != HASH_VAL) { throw CDTAccessException(); }
 
-return ConstIterator(u.p_data -> u.m_data -> begin());
+return CDTConstIterator(u.p_data -> u.m_data -> begin());
 }
 
 //
 // Get constant iterator pointed to end of hash
 //
-CDT::ConstIterator CDT::End() const
+CDTConstIterator CDT::End() const
 {
 	if (eValueType != HASH_VAL) { throw CDTAccessException(); }
 
-return ConstIterator(u.p_data -> u.m_data -> end());
+return CDTConstIterator(u.p_data -> u.m_data -> end());
 }
 
 //
 // Find element in hash
 //
-CDT::ConstIterator CDT::Find(const STLW::string & sKey) const
+CDTConstIterator CDT::Find(const STLW::string & sKey) const
 {
 	if (eValueType != HASH_VAL) { throw CDTAccessException(); }
 
-return ConstIterator(u.p_data -> u.m_data -> find(sKey));
+return CDTConstIterator(u.p_data -> u.m_data -> find(sKey));
 }
 
 // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -4138,7 +4138,7 @@ void CDT::DumpData(UINT_32 iLevel, UINT_32 iOffset, co
 
 		case HASH_VAL:
 			{
-				ConstIterator itHash = oData.Begin();
+				CDTConstIterator itHash = oData.Begin();
 				if (itHash == oData.End())
 				{
 					if (!bGlobalScope) { sResult += "{ }"; }
