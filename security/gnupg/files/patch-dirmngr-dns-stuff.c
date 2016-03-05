--- dirmngr/dns-stuff.c.orig	2016-01-26 18:36:37.000000000 +0900
+++ dirmngr/dns-stuff.c	2016-02-19 11:20:58.885089458 +0900
@@ -177,13 +177,17 @@
     case EAI_BADFLAGS:  err = gpg_error (GPG_ERR_INV_FLAG); break;
     case EAI_FAIL:      err = gpg_error (GPG_ERR_SERVER_FAILED); break;
     case EAI_MEMORY:    err = gpg_error (GPG_ERR_ENOMEM); break;
+#ifdef EAI_NODATA 
     case EAI_NODATA:    err = gpg_error (GPG_ERR_NO_DATA); break;
+#endif
     case EAI_NONAME:    err = gpg_error (GPG_ERR_NO_NAME); break;
     case EAI_SERVICE:   err = gpg_error (GPG_ERR_NOT_SUPPORTED); break;
     case EAI_FAMILY:    err = gpg_error (GPG_ERR_EAFNOSUPPORT); break;
     case EAI_SOCKTYPE:  err = gpg_error (GPG_ERR_ESOCKTNOSUPPORT); break;
 #ifndef HAVE_W32_SYSTEM
+#ifdef EAI_ADDRFAMILY
     case EAI_ADDRFAMILY:err = gpg_error (GPG_ERR_EADDRNOTAVAIL); break;
+#endif
     case EAI_SYSTEM:    err = gpg_error_from_syserror (); break;
 #endif
     default:            err = gpg_error (GPG_ERR_UNKNOWN_ERRNO); break;
