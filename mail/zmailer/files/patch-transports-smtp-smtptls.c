--- transports/smtp/smtptls.c.orig	2008-02-13 12:44:21.000000000 +0100
+++ transports/smtp/smtptls.c	2008-02-13 12:45:10.000000000 +0100
@@ -1878,7 +1878,11 @@
 	      e = EAGAIN;
 	      break;
 	    case SSL_ERROR_SSL:
+#ifdef EPROTO
 	      e = EPROTO;
+#else
+         e = 1;
+#endif
 	    default:
 	      SS->TLS.wantreadwrite = 0;
 	      break;
@@ -2056,7 +2060,11 @@
 	    e = EAGAIN;
 	    break;
 	  case SSL_ERROR_SSL:
+#ifdef EPROTO
 	    e = EPROTO;
+#else
+       e = 1;
+#endif
 	  default:
 	    SS->TLS.wantreadwrite =  0;
 	    break;
