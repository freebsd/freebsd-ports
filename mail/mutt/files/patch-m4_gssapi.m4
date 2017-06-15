--- m4/gssapi.m4.orig	2016-10-08 19:30:21 UTC
+++ m4/gssapi.m4
@@ -27,6 +27,7 @@ AC_DEFUN([MUTT_AM_PATH_GSSAPI],
     GSSAPI_LIBS="`$KRB5CFGPATH --libs gssapi`"
     case "`$KRB5CFGPATH --version`" in
       "Kerberos 5 "*)	GSSAPI_IMPL="MIT";;
+      "FreeBSD heimdal"*)		GSSAPI_IMPL="Heimdal";;
       ?eimdal*)		GSSAPI_IMPL="Heimdal";;
       *)		GSSAPI_IMPL="Unknown";;
    esac
