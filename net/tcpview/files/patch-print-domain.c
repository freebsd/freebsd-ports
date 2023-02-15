--- print-domain.c.orig	1993-04-22 20:40:15 UTC
+++ print-domain.c
@@ -137,10 +137,10 @@ ns_qprint(cp, bp, ep)
 	case T_HINFO:	printf(" HINFO"); break;
 	case T_MINFO:	printf(" MINFO"); break;
 	case T_MX:	printf(" MX"); break;
+#ifdef T_UNSPEC
 	case T_UINFO:	printf(" UINFO"); break;
 	case T_UID:	printf(" UID"); break;
 	case T_GID:	printf(" GID"); break;
-#ifdef T_UNSPEC
 	case T_UNSPEC:	printf(" UNSPEC"); break;
 #endif
 	case T_AXFR:	printf(" AXFR"); break;
@@ -213,10 +213,10 @@ ns_rprint(cp, bp, ep)
 			}
 #endif
 			break;
+#ifdef T_UNSPEC
 	case T_UINFO:	printf(" UINFO"); break;
 	case T_UID:	printf(" UID"); break;
 	case T_GID:	printf(" GID"); break;
-#ifdef T_UNSPEC
 	case T_UNSPEC:	printf(" UNSPEC"); break;
 #endif
 	case T_AXFR:	printf(" AXFR"); break;
