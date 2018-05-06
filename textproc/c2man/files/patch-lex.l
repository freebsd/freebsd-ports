--- lex.l.orig	2000-02-25 01:41:11 UTC
+++ lex.l
@@ -167,6 +167,7 @@ QUOTED		({STRING}|\'(\\\'|[^'\n])*\'|\\.
 <INITIAL>float		return T_FLOAT;
 <INITIAL>int		return T_INT;
 <INITIAL>void		return T_VOID;
+<INITIAL>__builtin_va_list return T_VALIST;
 <INITIAL>long		return T_LONG;
 <INITIAL>short		return T_SHORT;
 <INITIAL>signed		return T_SIGNED;
