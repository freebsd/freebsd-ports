# http://bugzilla.mozilla.org/attachment.cgi?id=84336&action=view
# http://bugzilla.mozilla.org/show_bug.cgi?id=86446
# patch by Glen Nakamura <glen@imodulo.com> to enable compilation with gcc 3.1 on Alpha 

Index: xptcinvoke_linux_alpha.cpp
===================================================================
RCS file: /cvsroot/mozilla/xpcom/reflect/xptcall/src/md/unix/xptcinvoke_linux_alpha.cpp,v
retrieving revision 1.3.38.1
diff -c -3 -p -r1.3.38.1 xptcinvoke_linux_alpha.cpp
*** xpcom/reflect/xptcall/src/md/unix/xptcinvoke_linux_alpha.cpp	10 Apr 2002 03:37:38 -0000	1.3.38.1
--- xpcom/reflect/xptcall/src/md/unix/xptcinvoke_linux_alpha.cpp	20 May 2002 22:37:04 -0000
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
  
  /* Platform specific code to invoke XPCOM methods on native objects */
  
- /* contributed by Glen Nakamura <glen.nakamura@usa.net> */
- 
  #include "xptcprivate.h"
  
  /* Prototype specifies unmangled function name and disables unused warning */
--- 38,43 ----
*************** __asm__(
*** 163,169 ****
--- 162,172 ----
      "bis $16,$16,$1\n\t"    /* load "this" */
      "ldq $2,16($15)\n\t"    /* load "methodIndex" */
      "ldq $1,0($1)\n\t"      /* load vtable */
+ #if defined(__GXX_ABI_VERSION) && __GXX_ABI_VERSION >= 100 /* G++ V3 ABI */
+     "s8addq $2,$31,$2\n\t"  /* vtable index = "methodIndex" * 8 */
+ #else /* not G++ V3 ABI */
      "s8addq $2,16,$2\n\t"   /* vtable index = "methodIndex" * 8 + 16 */
+ #endif /* G++ V3 ABI */
      "addq $1,$2,$1\n\t"
      "ldq $27,0($1)\n\t"     /* load address of function */
      "jsr $26,($27),0\n\t"   /* call virtual function */
*************** __asm__(
*** 176,179 ****
      "ret $31,($26),1\n\t"
      ".end XPTC_InvokeByIndex"
      );
- 
--- 179,181 ----
