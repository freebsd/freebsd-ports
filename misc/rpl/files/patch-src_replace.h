
$FreeBSD$

--- src/replace.h.orig
+++ src/replace.h
@@ -77,8 +77,7 @@
 
 /* This is a simple macro to call malloc() and die if it returns null */
 #define MALLOC_FAIL_STRING   ("\n" PACKAGE " Unable to allocate memory!")
-#define MALLOC_AND_CHECK( x, y )       (void*)(x)=malloc((y));if(x==NULL){fprintf(stderr,"\n%s --> %s:%d\n", MALLOC_FAIL_STRING, __FILE__, __LINE__ );exit(EX_OSERR);}
-	
+#define MALLOC_AND_CHECK( x, y )       (x)=malloc((y));if(x==NULL){fprintf(stderr,"\n%s --> %s:%d\n", MALLOC_FAIL_STRING, __FILE__, __LINE__ );exit(EX_OSERR);}
 
 /*  Function Prototypes */
 
@@ -90,4 +89,5 @@
 
 static void EchoFeedback(int, int, int, char*);
 
-static void SetPerms(struct stat, int, int, char*, int* );
\ No newline at end of file
+static void SetPerms(struct stat, int, int, char*, int* );
+
