--- libwsmake/wsUtil.h.orig	Thu Sep 15 09:39:51 2005
+++ libwsmake/wsUtil.h	Thu Sep 15 09:38:34 2005
@@ -77,7 +77,7 @@ namespace std
   void __wsmake_print_error(const char *, ...);
   void __wsmake_print(const char *, ...);
   void __wsmake_print(int, const char *, ...);
-  void __wsmake_print_it(FILE *, const char *, const va_list *);
+  void __wsmake_print_it(FILE *, const char *, va_list *);
 }
 
 #endif /* __WSUTIL_H__ */
