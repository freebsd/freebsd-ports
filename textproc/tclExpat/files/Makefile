#
# $FreeBSD$
#
SRCS=	tclexpat.c

SHLIB_NAME=	libtclexpat.so.1
LIBDIR=	${LOCALBASE}/lib

TCL_VERSION?=	8.3
TCL_DVER?=	${TCL_VERSION:S/.//}

CFLAGS+= -I${LOCALBASE}/include/tcl${TCL_VERSION} -I${LOCALBASE}/include -Wall
LDADD+=	-L${LOCALBASE}/lib -lexpat

USE_STUBS!=	. ${LOCALBASE}/lib/tcl${TCL_VERSION}/tclConfig.sh; echo $$TCL_SUPPORTS_STUBS

.if ${USE_STUBS} == "1"
LDADD+=	-ltclstub${TCL_DVER}
CFLAGS+=-DUSE_TCL_STUBS
.else
LDADD+= -ltcl${TCL_DVER}
.endif

.include <bsd.lib.mk>
