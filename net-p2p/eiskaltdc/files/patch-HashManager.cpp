--- dcpp/HashManager.cpp.orig	2010-05-27 09:13:46.000000000 +0700
+++ dcpp/HashManager.cpp	2010-05-27 09:14:01.000000000 +0700
@@ -32,6 +32,49 @@
 #include <setjmp.h>
 #endif
 
+#ifndef ILL_ILLOPC
+#define ILL_ILLOPC      1       /* illegal opcode */
+#define ILL_ILLOPN      2       /* illegal operand */
+#define ILL_ILLADR      3       /* illegal addressing mode */
+#define ILL_ILLTRP      4       /* illegal trap */
+#define ILL_PRVOPC      5       /* privileged opcode */
+#define ILL_PRVREG      6       /* privileged register */
+#define ILL_COPROC      7       /* coprocessor error */
+#define ILL_BADSTK      8       /* internal stack error */
+#define FPE_INTDIV      1       /* integer divide by zero */
+#define FPE_INTOVF      2       /* integer overflow */
+#define FPE_FLTDIV      3       /* floating point divide by zero */
+#define FPE_FLTOVF      4       /* floating point overflow */
+#define FPE_FLTUND      5       /* floating point underflow */
+#define FPE_FLTRES      6       /* floating point inexact result */
+#define FPE_FLTINV      7       /* floating point invalid operation */
+#define FPE_FLTSUB      8       /* subscript out of range */
+#define SEGV_MAPERR     1       /* address not mapped to object */
+#define SEGV_ACCERR     2       /* invalid permissions for mapped object */
+#define BUS_ADRALN      1       /* invalid address alignment */
+#define BUS_ADRERR      2       /* non-existant physical address */
+#define BUS_OBJERR      3       /* object specific hardware error */
+#define TRAP_BRKPT      1       /* process breakpoint */
+#define TRAP_TRACE      2       /* process trace trap */
+#define CLD_EXITED      1       /* child has exited */
+#define CLD_KILLED      2       /* child was killed */
+#define CLD_DUMPED      3       /* child terminated abnormally */
+#define CLD_TRAPPED     4       /* traced child has trapped */
+#define CLD_STOPPED     5       /* child has stopped */
+#define CLD_CONTINUED   6       /* stopped child has continued */
+#define POLL_IN         1       /* data input available */
+#define POLL_OUT        2       /* output buffers available */
+#define POLL_MSG        3       /* input message available */
+#define POLL_ERR        4       /* i/o error */
+#define POLL_PRI        5       /* high priority input available */
+#define POLL_HUP        6       /* device disconnected */
+#define SI_USER         0       /* sent by kill, sigsend, raise */
+#define SI_QUEUE        -1      /* sent by sigqueue */
+#define SI_TIMER        -2      /* sent by timer expiration */
+#define SI_MESGQ        -3      /* sent by real time mesq state change */
+#define SI_ASYNCIO      -4      /* sent by AIO completion */
+#endif
+
 namespace dcpp {
 
 #define HASH_FILE_VERSION_STRING "2"
