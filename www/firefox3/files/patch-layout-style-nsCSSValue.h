# Ensure correct alignment for nsCSSValue objects inside nsCSSValue::Array.
#  (Bug 476345)

--- layout/style/nsCSSValue.h.orig	2008-07-02 00:51:43.000000000 +0200
+++ layout/style/nsCSSValue.h	2009-02-01 21:43:29.000000000 +0100
@@ -286,104 +286,7 @@
   // failure.
   static nsStringBuffer* BufferFromString(const nsString& aValue);
   
-  struct Array {
-
-    // return |Array| with reference count of zero
-    static Array* Create(PRUint16 aItemCount) {
-      return new (aItemCount) Array(aItemCount);
-    }
-
-    nsCSSValue& operator[](PRUint16 aIndex) {
-      NS_ASSERTION(aIndex < mCount, "out of range");
-      return *(First() + aIndex);
-    }
-
-    const nsCSSValue& operator[](PRUint16 aIndex) const {
-      NS_ASSERTION(aIndex < mCount, "out of range");
-      return *(First() + aIndex);
-    }
-
-    nsCSSValue& Item(PRUint16 aIndex) { return (*this)[aIndex]; }
-    const nsCSSValue& Item(PRUint16 aIndex) const { return (*this)[aIndex]; }
-
-    PRUint16 Count() const { return mCount; }
-
-    PRBool operator==(const Array& aOther) const
-    {
-      if (mCount != aOther.mCount)
-        return PR_FALSE;
-      for (PRUint16 i = 0; i < mCount; ++i)
-        if ((*this)[i] != aOther[i])
-          return PR_FALSE;
-      return PR_TRUE;
-    }
-
-    void AddRef() {
-      if (mRefCnt == PR_UINT16_MAX) {
-        NS_WARNING("refcount overflow, leaking nsCSSValue::Array");
-        return;
-      }
-      ++mRefCnt;
-      NS_LOG_ADDREF(this, mRefCnt, "nsCSSValue::Array", sizeof(*this));
-    }
-    void Release() {
-      if (mRefCnt == PR_UINT16_MAX) {
-        NS_WARNING("refcount overflow, leaking nsCSSValue::Array");
-        return;
-      }
-      --mRefCnt;
-      NS_LOG_RELEASE(this, mRefCnt, "nsCSSValue::Array");
-      if (mRefCnt == 0)
-        delete this;
-    }
-
-  private:
-
-    PRUint16 mRefCnt;
-    PRUint16 mCount;
-
-    void* operator new(size_t aSelfSize, PRUint16 aItemCount) CPP_THROW_NEW {
-      return ::operator new(aSelfSize + sizeof(nsCSSValue)*aItemCount);
-    }
-
-    void operator delete(void* aPtr) { ::operator delete(aPtr); }
-
-    nsCSSValue* First() {
-      return (nsCSSValue*) (((char*)this) + sizeof(*this));
-    }
-
-    const nsCSSValue* First() const {
-      return (const nsCSSValue*) (((const char*)this) + sizeof(*this));
-    }
-
-#define CSSVALUE_LIST_FOR_VALUES(var)                                         \
-  for (nsCSSValue *var = First(), *var##_end = var + mCount;                  \
-       var != var##_end; ++var)
-
-    Array(PRUint16 aItemCount)
-      : mRefCnt(0)
-      , mCount(aItemCount)
-    {
-      MOZ_COUNT_CTOR(nsCSSValue::Array);
-      CSSVALUE_LIST_FOR_VALUES(val) {
-        new (val) nsCSSValue();
-      }
-    }
-
-    ~Array()
-    {
-      MOZ_COUNT_DTOR(nsCSSValue::Array);
-      CSSVALUE_LIST_FOR_VALUES(val) {
-        val->~nsCSSValue();
-      }
-    }
-
-#undef CSSVALUE_LIST_FOR_VALUES
-
-  private:
-    Array(const Array& aOther); // not to be implemented
-  };
-
+  struct Array;
   struct URL {
     // Methods are not inline because using an nsIPrincipal means requiring
     // caps, which leads to REQUIRES hell, since this header is included all
@@ -454,5 +357,102 @@
   }         mValue;
 };
 
-#endif /* nsCSSValue_h___ */
+struct nsCSSValue::Array {
+
+  // return |Array| with reference count of zero
+  static Array* Create(PRUint16 aItemCount) {
+    return new (aItemCount) Array(aItemCount);
+  }
+
+  nsCSSValue& operator[](PRUint16 aIndex) {
+    NS_ASSERTION(aIndex < mCount, "out of range");
+    return mArray[aIndex];
+  }
+
+  const nsCSSValue& operator[](PRUint16 aIndex) const {
+    NS_ASSERTION(aIndex < mCount, "out of range");
+    return mArray[aIndex];
+  }
+
+  nsCSSValue& Item(PRUint16 aIndex) { return (*this)[aIndex]; }
+  const nsCSSValue& Item(PRUint16 aIndex) const { return (*this)[aIndex]; }
+
+  PRUint16 Count() const { return mCount; }
+
+  PRBool operator==(const Array& aOther) const
+  {
+    if (mCount != aOther.mCount)
+      return PR_FALSE;
+    for (PRUint16 i = 0; i < mCount; ++i)
+      if ((*this)[i] != aOther[i])
+        return PR_FALSE;
+    return PR_TRUE;
+  }
+
+  void AddRef() {
+    if (mRefCnt == PR_UINT16_MAX) {
+      NS_WARNING("refcount overflow, leaking nsCSSValue::Array");
+      return;
+    }
+    ++mRefCnt;
+    NS_LOG_ADDREF(this, mRefCnt, "nsCSSValue::Array", sizeof(*this));
+  }
+  void Release() {
+    if (mRefCnt == PR_UINT16_MAX) {
+      NS_WARNING("refcount overflow, leaking nsCSSValue::Array");
+      return;
+    }
+    --mRefCnt;
+    NS_LOG_RELEASE(this, mRefCnt, "nsCSSValue::Array");
+    if (mRefCnt == 0)
+      delete this;
+  }
+
+private:
+
+  PRUint16 mRefCnt;
+  const PRUint16 mCount;
+  // This must be the last sub-object, since we extend this array to
+  // be of size mCount; it needs to be a sub-object so it gets proper
+  // alignment.
+  nsCSSValue mArray[1];
 
+  void* operator new(size_t aSelfSize, PRUint16 aItemCount) CPP_THROW_NEW {
+    return ::operator new(aSelfSize + sizeof(nsCSSValue) * (aItemCount - 1));
+  }
+
+  void operator delete(void* aPtr) { ::operator delete(aPtr); }
+
+  nsCSSValue* First() { return mArray; }
+
+  const nsCSSValue* First() const { return mArray; }
+
+#define CSSVALUE_LIST_FOR_EXTRA_VALUES(var)                                   \
+for (nsCSSValue *var = First() + 1, *var##_end = First() + mCount;          \
+     var != var##_end; ++var)
+
+  Array(PRUint16 aItemCount)
+    : mRefCnt(0)
+    , mCount(aItemCount)
+  {
+    MOZ_COUNT_CTOR(nsCSSValue::Array);
+    CSSVALUE_LIST_FOR_EXTRA_VALUES(val) {
+      new (val) nsCSSValue();
+    }
+  }
+
+  ~Array()
+  {
+    MOZ_COUNT_DTOR(nsCSSValue::Array);
+    CSSVALUE_LIST_FOR_EXTRA_VALUES(val) {
+      val->~nsCSSValue();
+    }
+  }
+
+#undef CSSVALUE_LIST_FOR_VALUES
+
+private:
+  Array(const Array& aOther); // not to be implemented
+};
+
+#endif /* nsCSSValue_h___ */
