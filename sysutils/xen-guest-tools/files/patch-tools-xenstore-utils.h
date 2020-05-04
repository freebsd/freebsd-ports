--- tools/xenstore/utils.h.orig	2019-12-17 14:23:09 UTC
+++ tools/xenstore/utils.h
@@ -24,7 +24,7 @@ static inline bool strends(const char *a, const char *
 void barf(const char *fmt, ...) __attribute__((noreturn));
 void barf_perror(const char *fmt, ...) __attribute__((noreturn));
 
-void (*xprintf)(const char *fmt, ...);
+extern void (*xprintf)(const char *fmt, ...);
 
 #define eprintf(_fmt, _args...) xprintf("[ERR] %s" _fmt, __FUNCTION__, ##_args)
 
