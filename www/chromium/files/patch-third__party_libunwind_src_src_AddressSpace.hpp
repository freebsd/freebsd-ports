--- third_party/libunwind/src/src/AddressSpace.hpp.orig	2026-02-11 09:05:39 UTC
+++ third_party/libunwind/src/src/AddressSpace.hpp
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/tree.h>
 
 #include "libunwind.h"
 #include "config.h"
@@ -157,7 +158,63 @@ struct UnwindInfoSections {
 #endif
 };
 
+class UnwindInfoSectionsCache {
+public:
 
+  struct CacheItem {
+    CacheItem(UnwindInfoSections &uis, uintptr_t pc)
+      : m_uis(uis), m_pc(pc) {
+    }
+    CacheItem(uintptr_t pc)
+      : m_pc(pc) {
+    }
+
+    UnwindInfoSections m_uis;
+    uintptr_t m_pc;
+
+    RB_ENTRY(CacheItem) entry;
+  };
+
+  typedef uintptr_t CacheItemKey;
+
+  int CacheCmp(struct CacheItem *c1, struct CacheItem *c2) {
+    return (c1->m_pc < c2->m_pc ? -1 : c1->m_pc > c2->m_pc);
+  }
+
+  UnwindInfoSectionsCache() {
+    m_head = RB_INITIALIZER(&head);
+  }
+
+  bool getUnwindInfoSectionsForPC(CacheItemKey key, UnwindInfoSections &uis) {
+    UnwindInfoSections *result = nullptr;
+    if (m_prev_req_item && m_prev_req_item->m_pc == key)
+      result = &m_prev_req_item->m_uis;
+    else {
+      struct CacheItem find(key), *res;
+      res = RB_FIND(CacheTree, &m_head, &find);
+      if (res) {
+        m_prev_req_item = res;
+        result = &res->m_uis;
+      }
+    }
+    if (result) {
+      uis = *result;
+      return true;
+    }
+    return false;
+  }
+
+  void setUnwindInfoSectionsForPC(CacheItemKey key, UnwindInfoSections &uis) {
+    CacheItem *p_item(new CacheItem(uis, key));
+    RB_INSERT(CacheTree, &m_head, p_item);
+  }
+
+private:
+  CacheItem *m_prev_req_item = nullptr;
+  RB_HEAD(CacheTree, CacheItem) m_head;
+  RB_GENERATE(CacheTree, CacheItem, entry, CacheCmp);
+};
+
 /// LocalAddressSpace is used as a template parameter to UnwindCursor when
 /// unwinding a thread in the same process.  The wrappers compile away,
 /// making local unwinds fast.
@@ -283,6 +340,10 @@ LocalAddressSpace::getEncodedP(pint_t &addr, pint_t en
   pint_t startAddr = addr;
   const uint8_t *p = (uint8_t *)addr;
   pint_t result;
+
+  if (encoding == DW_EH_PE_omit) {
+    return (pint_t)NULL;
+  }
 
   // first get value
   switch (encoding & 0x0F) {
