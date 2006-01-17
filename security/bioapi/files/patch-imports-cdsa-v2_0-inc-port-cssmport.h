--- imports/cdsa/v2_0/inc/port/cssmport.h	Wed Jun  8 02:51:05 2005
+++ imports/cdsa/v2_0/inc/port/cssmport.h	Tue Jan 17 16:44:06 2006
@@ -17,9 +17,9 @@
 #ifndef _CSSMPORT_H
 #define _CSSMPORT_H    
 
-#if defined (POSIX)
+#if defined (__POSIX_VISIBLE)
 #include <pthread.h>  /* Must always be the first include */
-#endif  /* POSIX */
+#endif  /* __POSIX_VISIBLE */
 
 #if defined (WIN32)
 #pragma warning (disable:4201 4514 4214 4115)
@@ -27,7 +27,7 @@
 #pragma warning (default:4201 4214 4115)
 #endif  /* WIN32 */
 
-#if defined (UNIX)
+#if defined (__unix__)
 /* For UNIX C library calls */
 #if defined (LINUX) || defined (SOLARIS)
 #include <link.h>
@@ -37,7 +37,6 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <limits.h>
-#include <malloc.h>
 #include <dlfcn.h>
 #include <ctype.h>
 #include <fcntl.h>
@@ -52,7 +51,7 @@
 #include <sys/mman.h>
 #include <sys/file.h>
 #include <pwd.h>
-#endif  /* UNIX */
+#endif  /* __unix__ */
 
 #if defined (AIX)
 #include <strings.h> 
@@ -64,7 +63,7 @@
 #include <sys/stat.h>
 #include "cssmtype.h"
 
-#if defined(UNIX)
+#if defined(__unix__)
 
 /* _MAX_PATH includes room for 0-terminator, PATH_MAX doesn't. */
 #define _MAX_PATH (PATH_MAX + 1)
@@ -81,12 +80,12 @@
 
 typedef void * UNIX_HANDLE;
 
-#endif /* UNIX */
+#endif /* __unix__ */
 
 #if defined(WIN32)
 #define CSSM_MAX_PATH	_MAX_PATH + 1
 #define CSSM_MAX_REG	REGSTR_MAX_VALUE_LENGTH + 1
-#elif defined (UNIX)
+#elif defined (__unix__)
 #define CSSM_MAX_PATH	(PATH_MAX + 1)
 #define CSSM_MAX_REG 256
 #else
@@ -95,7 +94,7 @@
 #endif  /* WIN32 */
 
 
-#if defined (POSIX)
+#if defined (__POSIX_VISIBLE)
 #define CSSM_POLL_INT                   20 /* polling interval in ms */
 #endif
 
@@ -115,12 +114,12 @@
 #define __stdcall
 #endif
 
-#if defined (UNIX) || defined (AIX)
+#if defined (__unix__) || defined (AIX)
 #define CDSA_SYSDIR	"/var/cdsa"
 #endif
 
 /* Linux-Port: Default location of BioAPI db/registry files */
-#if defined (UNIX)
+#if defined (__unix__)
 #define BioAPI_SYSDIR	MDS_PATH
 #endif
 
@@ -343,7 +342,7 @@
 
 #if defined (WIN32)
 typedef HANDLE PORT_MUTEX_HANDLE;
-#elif defined (POSIX)
+#elif defined (__POSIX_VISIBLE)
 typedef pthread_mutex_t* PORT_MUTEX_HANDLE;
 #else
 typedef void* PORT_MUTEX_HANDLE;
@@ -377,11 +376,11 @@
  */
 #if defined(WIN32)
 #define PORT_STATIC_MUTEX_INITIALIZER NULL
-#elif defined(POSIX)
+#elif defined(__POSIX_VISIBLE)
 #define PORT_STATIC_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
 #endif
 
-#if defined (UNIX)
+#if defined (__unix__)
 #define GetCurrentDirectory(size, dir) \
     (port_getcwd(dir, size) == CSSM_OK ? strlen(dir) : 0)
 #define DeleteFile unlink
@@ -437,7 +436,7 @@
                        sint32 buf_length);
 
 
-#ifdef POSIX
+#ifdef __POSIX_VISIBLE
 typedef pthread_t PORT_THREAD_HANDLE;
 #elif defined ( WIN32 )
 typedef HANDLE PORT_THREAD_HANDLE;
@@ -464,7 +463,7 @@
 /* Thread local storage management */
 #if defined (WIN32)
 typedef DWORD PORT_TLS_INDEX;
-#elif defined (POSIX)
+#elif defined (__POSIX_VISIBLE)
 typedef pthread_key_t PORT_TLS_INDEX;
 #else
 typedef uint32 PORT_TLS_INDEX;
@@ -509,7 +508,7 @@
 
 #if defined(WIN32)
 typedef DWORD PORT_FLOCK_OFFSET;
-#elif defined(UNIX)
+#elif defined(__unix__)
 typedef off_t PORT_FLOCK_OFFSET;
 #else
 typedef uint32 PORT_FLOCK_OFFSET;
@@ -549,7 +548,7 @@
 #define CSSM_MAP_READWRITE          FILE_MAP_ALL_ACCESS
 #define CSSM_MAP_READ               FILE_MAP_READ
 
-#elif defined (UNIX)
+#elif defined (__unix__)
 
 #include <fcntl.h>
 #include <sys/mman.h>
@@ -591,7 +590,7 @@
 
 
 /* Misc. functions */
-#if defined (UNIX)
+#if defined (__unix__)
 #define _timezone timezone
 #define itoa(value,string,radix) sprintf ((string),"%d",(value))
 #define _itoa(value,string,radix) sprintf ((string),"%d",(value))
@@ -609,7 +608,7 @@
 port_getcwd(char *dir, 
 			uint32 size);
 
-#ifdef UNIX
+#ifdef __unix__
 #include <stdarg.h> 
 
 void port_syslog(int Facility, int Priority, char* format, ...);
@@ -647,6 +646,7 @@
 #define __arch64__
 #endif /* __ia64__ */
 
+#if 0
 #ifdef __arch64__
 typedef Elf64_Addr Elf_Addr;
 typedef Elf64_Word Elf_Word;
@@ -670,6 +670,7 @@
 typedef Elf32_Shdr Elf_Shdr;
 #define ELF_R_TYPE ELF32_R_TYPE
 #endif /* __arch64__ */
+#endif
 
 #endif /* ELF_FORMAT */
 
@@ -719,7 +720,7 @@
 #define DLL_STR "so"
 #endif
 
-#if defined (UNIX)
+#if defined (__unix__)
 #define CSSM_CDSA_SYSLOG_IDENT		"CDSA"
 
 /* Priorities (ordered) */
