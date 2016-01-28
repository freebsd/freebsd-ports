--- m4/gssapi.m4.orig	2015-08-30 19:06:38.000000000 +0200
+++ m4/gssapi.m4	2016-01-25 15:04:37.448609000 +0100
@@ -27,6 +27,7 @@
     GSSAPI_LIBS="$MUTTLIBS `$KRB5CFGPATH --libs gssapi`"
     case "`$KRB5CFGPATH --version`" in
       "Kerberos 5 "*)	GSSAPI_IMPL="MIT";;
+      "FreeBSD heimdal"*)		GSSAPI_IMPL="Heimdal";;
       ?eimdal*)		GSSAPI_IMPL="Heimdal";;
       *)		GSSAPI_IMPL="Unknown";;
    esac
