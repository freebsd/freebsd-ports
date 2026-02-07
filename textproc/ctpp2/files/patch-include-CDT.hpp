--- include/CDT.hpp.orig	2012-11-11 01:45:43.000000000 +0400
+++ include/CDT.hpp	2014-05-02 18:06:25.481307400 +0400
@@ -48,13 +48,16 @@
 
 #define C_MAX_SPRINTF_LENGTH 128
 
+class CTPP2DECL CDTConstIterator;
+class CTPP2DECL CDTIterator;
+
 /**
   @class CDT CDT.hpp <CDT.hpp>
   @brief Common Data Type
 */
 class CTPP2DECL CDT
 {
-private:
+public:
 	/**
 	  @var typedef STLW::string<CDT> String
 	  @brief internal string definition
@@ -72,7 +75,7 @@
 	  @brief internal hash definition
 	*/
 	typedef STLW::map<String, CDT>  Map;
-public:
+
 	/**
 	  @enum eValType CDT.hpp <CDT.hpp>
 	  @brief Describes type of stored value
@@ -1768,172 +1771,39 @@
 		virtual ~SortingComparator() throw();
 	};
 
-	// FWD
-	class CTPP2DECL ConstIterator;
-
-	/**
-	  @class Iterator CDT.hpp <CDT.hpp>
-	  @brief CDT[HASH] forward iterator
-	*/
-	class CTPP2DECL Iterator
-	{
-	private:
-		friend class CDT;
-		friend class ConstIterator;
-
-		/** Hash iterator */
-		CDT::Map::iterator itMap;
-
-		/**
-		  @brief Constructor
-		  @param itIMap - map iterator
-		*/
-		Iterator(CDT::Map::iterator itIMap);
-	public:
-		/**
-		  @brief Copy constructor
-		  @param oRhs - object to copy
-		*/
-		Iterator(const Iterator & oRhs);
-
-		/**
-		  @brief Operator =
-		  @param oRhs - object to copy
-		*/
-		Iterator & operator=(const Iterator & oRhs);
-
-		/**
-		  @brief Pre-increment operator ++
-		*/
-		Iterator & operator++();
-
-		/**
-		  @brief Post-increment operator ++
-		*/
-		Iterator operator++(int);
-
-		/**
-		  @brief Access operator
-		  @return Pair of key => value
-		*/
-		STLW::pair<const STLW::string, CDT> * operator->();
-
-		/**
-		  @brief Comparison operator
-		  @param oRhs - object to compare
-		  @return true if objects are equal
-		*/
-		bool operator ==(const Iterator & oRhs);
-
-		/**
-		  @brief Comparison operator
-		  @param oRhs - object to compare
-		  @return true if objects are NOT equal
-		*/
-		bool operator !=(const Iterator & oRhs);
-	};
-
 	/**
 	  @brief Get iterator pointed to start of hash
 	*/
-	Iterator Begin();
+	CDTIterator Begin();
 
 	/**
 	  @brief Get iterator pointed to end of hash
 	*/
-	Iterator End();
+	CDTIterator End();
 
 	/**
 	  @brief Find element in hash
 	  @param sKey - element name
 	  @return Iterator pointed to element or to end of hash if nothing found
 	*/
-	Iterator Find(const STLW::string & sKey);
-
-	/**
-	  @class ConstIterator CDT.hpp <CDT.hpp>
-	  @brief CDT[HASH] forward constant iterator
-	*/
-	class CTPP2DECL ConstIterator
-	{
-	private:
-		friend class CDT;
-
-		/** Hash iterator */
-		CDT::Map::const_iterator itMap;
-
-	public:
-		/**
-		  @brief Copy constructor
-		  @param oRhs - object to copy
-		*/
-		ConstIterator(const ConstIterator & oRhs);
-
-		/**
-		  @brief Type cast constructor
-		  @param oRhs - object to copy
-		*/
-		ConstIterator(const Iterator & oRhs);
-
-		/**
-		  @brief Operator =
-		  @param oRhs - object to copy
-		*/
-		ConstIterator & operator=(const ConstIterator & oRhs);
-
-		/**
-		  @brief Operator =
-		  @param oRhs - object to copy
-		*/
-		ConstIterator & operator=(const Iterator & oRhs);
-
-		/**
-		  @brief Pre-increment operator ++
-		*/
-		ConstIterator & operator++();
-
-		/**
-		  @brief Post-increment operator ++
-		*/
-		ConstIterator operator++(int);
-
-		/**
-		  @brief Access operator
-		  @return Pair of key => value
-		*/
-		const STLW::pair<const STLW::string, CDT> * operator->() const;
-
-		/**
-		  @brief Comparison operator
-		  @param oRhs - object to compare
-		  @return true if objects are equal
-		*/
-		bool operator ==(const ConstIterator & oRhs) const;
-
-		/**
-		  @brief Comparison operator
-		  @param oRhs - object to compare
-		  @return true if objects are NOT equal
-		*/
-		bool operator !=(const ConstIterator & oRhs) const;
-	};
+	CDTIterator Find(const STLW::string & sKey);
 
 	/**
 	  @brief Get constant iterator pointed to start of hash
 	*/
-	ConstIterator Begin() const;
+	CDTConstIterator Begin() const;
 
 	/**
 	  @brief Get constant iterator pointed to end of hash
 	*/
-	ConstIterator End() const;
+	CDTConstIterator End() const;
 
 	/**
 	  @brief Find element in hash
 	  @param sKey - element name
 	  @return Iterator pointed to element or to end of hash if nothing found
 	*/
-	ConstIterator Find(const STLW::string & sKey) const;
+	CDTConstIterator Find(const STLW::string & sKey) const;
 
 	/**
 	  @brief Try to cast value to integer or to IEEE floating point value
@@ -2009,6 +1879,139 @@
 
 };
 
+
+/**
+  @class CDTIterator CDT.hpp <CDT.hpp>
+  @brief CDT[HASH] forward iterator
+*/
+class CTPP2DECL CDTIterator
+{
+private:
+	friend class CDT;
+	friend class CDTConstIterator;
+
+	/** Hash iterator */
+	CDT::Map::iterator itMap;
+
+	/**
+	  @brief Constructor
+	  @param itIMap - map iterator
+	*/
+	CDTIterator(CDT::Map::iterator itIMap);
+public:
+	/**
+	  @brief Copy constructor
+	  @param oRhs - object to copy
+	*/
+	CDTIterator(const CDTIterator & oRhs);
+
+	/**
+	  @brief Operator =
+	  @param oRhs - object to copy
+	*/
+	CDTIterator & operator=(const CDTIterator & oRhs);
+
+	/**
+	  @brief Pre-increment operator ++
+	*/
+	CDTIterator & operator++();
+
+	/**
+	  @brief Post-increment operator ++
+	*/
+	CDTIterator operator++(int);
+
+	/**
+	  @brief Access operator
+	  @return Pair of key => value
+	*/
+	STLW::pair<const STLW::string, CDT> * operator->();
+
+	/**
+	  @brief Comparison operator
+	  @param oRhs - object to compare
+	  @return true if objects are equal
+	*/
+	bool operator ==(const CDTIterator & oRhs);
+
+	/**
+	  @brief Comparison operator
+	  @param oRhs - object to compare
+	  @return true if objects are NOT equal
+	*/
+	bool operator !=(const CDTIterator & oRhs);
+};
+
+
+/**
+  @class CDTConstIterator CDT.hpp <CDT.hpp>
+  @brief CDT[HASH] forward constant iterator
+*/
+class CTPP2DECL CDTConstIterator
+{
+private:
+	friend class CDT;
+
+	/** Hash iterator */
+	CDT::Map::const_iterator itMap;
+
+public:
+	/**
+	  @brief Copy constructor
+	  @param oRhs - object to copy
+	*/
+	CDTConstIterator(const CDTConstIterator & oRhs);
+
+	/**
+	  @brief Type cast constructor
+	  @param oRhs - object to copy
+	*/
+	CDTConstIterator(const CDTIterator & oRhs);
+
+	/**
+	  @brief Operator =
+	  @param oRhs - object to copy
+	*/
+	CDTConstIterator & operator=(const CDTConstIterator & oRhs);
+
+	/**
+	  @brief Operator =
+	  @param oRhs - object to copy
+	*/
+	CDTConstIterator & operator=(const CDTIterator & oRhs);
+
+	/**
+	  @brief Pre-increment operator ++
+	*/
+	CDTConstIterator & operator++();
+
+	/**
+	  @brief Post-increment operator ++
+	*/
+	CDTConstIterator operator++(int);
+
+	/**
+	  @brief Access operator
+	  @return Pair of key => value
+	*/
+	const STLW::pair<const STLW::string, CDT> * operator->() const;
+
+	/**
+	  @brief Comparison operator
+	  @param oRhs - object to compare
+	  @return true if objects are equal
+	*/
+	bool operator ==(const CDTConstIterator & oRhs) const;
+
+	/**
+	  @brief Comparison operator
+	  @param oRhs - object to compare
+	  @return true if objects are NOT equal
+	*/
+	bool operator !=(const CDTConstIterator & oRhs) const;
+};
+
+
 // ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //
 // Realization
