# http://bugzilla.mozilla.org/attachment.cgi?id=84336&action=view
# http://bugzilla.mozilla.org/show_bug.cgi?id=86446
# patch by Glen Nakamura <glen@imodulo.com> to enable compilation with gcc 3.1 on Alpha 

Index: xptcstubs_linux_alpha.cpp
===================================================================
RCS file: /cvsroot/mozilla/xpcom/reflect/xptcall/src/md/unix/xptcstubs_linux_alpha.cpp,v
retrieving revision 1.3.38.1
diff -c -3 -p -r1.3.38.1 xptcstubs_linux_alpha.cpp
*** xpcom/reflect/xptcall/src/md/unix/xptcstubs_linux_alpha.cpp	10 Apr 2002 03:37:42 -0000	1.3.38.1
--- xpcom/reflect/xptcall/src/md/unix/xptcstubs_linux_alpha.cpp	20 May 2002 22:37:04 -0000
***************
*** 20,25 ****
--- 20,26 ----
   * the Initial Developer. All Rights Reserved.
   *
   * Contributor(s):
+  *   Glen Nakamura <glen@imodulo.com>
   *
   * Alternatively, the contents of this file may be used under the terms of
   * either the GNU General Public License Version 2 or later (the "GPL"), or 
***************
*** 37,44 ****
  
  /* Implement shared vtbl methods. */
  
- /* contributed by Glen Nakamura <glen.nakamura@usa.net> */
- 
  #include "xptcprivate.h"
  
  /* Prototype specifies unmangled function name and disables unused warning */
--- 38,43 ----
*************** __asm__(
*** 188,210 ****
   * nsresult nsXPTCStubBase::Stub##n()
   *  Sets register $1 to "methodIndex" and jumps to SharedStub.
   */
  #define STUB_ENTRY(n) \
  __asm__( \
!     "#### Stub"#n" ####\n" \
! ".text\n\t" \
!     ".align 5\n\t" \
!     ".globl Stub"#n"__14nsXPTCStubBase\n\t" \
!     ".ent Stub"#n"__14nsXPTCStubBase\n" \
! "Stub"#n"__14nsXPTCStubBase:\n\t" \
!     ".frame $30,0,$26,0\n\t" \
!     "ldgp $29,0($27)\n" \
! "$Stub"#n"__14nsXPTCStubBase..ng:\n\t" \
!     ".prologue 1\n\t" \
!     "lda $1,"#n"\n\t" \
!     "br $31,$SharedStub..ng\n\t" \
!     ".end Stub"#n"__14nsXPTCStubBase" \
      );
  
  #define SENTINEL_ENTRY(n) \
  nsresult nsXPTCStubBase::Sentinel##n() \
  { \
--- 187,231 ----
   * nsresult nsXPTCStubBase::Stub##n()
   *  Sets register $1 to "methodIndex" and jumps to SharedStub.
   */
+ #define STUB_MANGLED_ENTRY(n, symbol) \
+     "#### Stub"#n" ####"      "\n\t" \
+     ".text"                   "\n\t" \
+     ".align 5"                "\n\t" \
+     ".globl " symbol          "\n\t" \
+     ".ent " symbol            "\n"   \
+ symbol ":"                    "\n\t" \
+     ".frame $30,0,$26,0"      "\n\t" \
+     "ldgp $29,0($27)"         "\n"   \
+ "$" symbol "..ng:"            "\n\t" \
+     ".prologue 1"             "\n\t" \
+     "lda $1,"#n               "\n\t" \
+     "br $31,$SharedStub..ng"  "\n\t" \
+     ".end " symbol
+ 
+ #if defined(__GXX_ABI_VERSION) && __GXX_ABI_VERSION >= 100 /* G++ V3 ABI */
+ 
+ #define STUB_ENTRY(n) \
+ __asm__( \
+     ".if "#n" < 10"                                              "\n\t" \
+         STUB_MANGLED_ENTRY(n, "_ZN14nsXPTCStubBase5Stub"#n"Ev")  "\n\t" \
+     ".elseif "#n" < 100"                                         "\n\t" \
+         STUB_MANGLED_ENTRY(n, "_ZN14nsXPTCStubBase6Stub"#n"Ev")  "\n\t" \
+     ".elseif "#n" < 1000"                                        "\n\t" \
+         STUB_MANGLED_ENTRY(n, "_ZN14nsXPTCStubBase7Stub"#n"Ev")  "\n\t" \
+     ".else"                                                      "\n\t" \
+     ".err \"Stub"#n" >= 1000 not yet supported.\""               "\n\t" \
+     ".endif" \
+     );
+ 
+ #else /* not G++ V3 ABI */
+ 
  #define STUB_ENTRY(n) \
  __asm__( \
!     STUB_MANGLED_ENTRY(n, "Stub"#n"__14nsXPTCStubBase") \
      );
  
+ #endif /* G++ V3 ABI */
+ 
  #define SENTINEL_ENTRY(n) \
  nsresult nsXPTCStubBase::Sentinel##n() \
  { \
*************** nsresult nsXPTCStubBase::Sentinel##n() \
*** 213,216 ****
  }
  
  #include "xptcstubsdef.inc"
- 
--- 234,236 ----
