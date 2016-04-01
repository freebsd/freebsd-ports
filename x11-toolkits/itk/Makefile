# Created by: chuckr
# $FreeBSD$

PORTNAME=	itk
PORTVERSION=	3.3
PORTREVISION=	3
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/incrtcl/%5BIncr%20Tcl_Tk%5D-source/${PORTVERSION}-RC
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Object-oriented extension to Tk [incr Tk]

LIB_DEPENDS=	libitcl.so.${MAJOR}:lang/itcl

USES=		tk uidfix
USE_LDCONFIG=	yes
MAKE_ENV+=	${PLIST_SUB} \
		SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR} \
		TK_SHLIB_VER=${TK_SHLIB_VER} TCL_INCLUDEDIR=${TCL_INCLUDEDIR} \
		TK_INCLUDEDIR=${TK_INCLUDEDIR}

MAKEFILE=	${FILESDIR}/Makefile.lib
SHLIB_MAJOR=	${MAJOR}
SHLIB_MINOR=	${MINOR}
MAJOR=		${PORTVERSION:R}
MINOR=		${PORTVERSION:E}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}
ITK_LIB=	libitk.so.${MAJOR}

ITK_LIB_FILE=	${ITK_LIB}.${SHLIB_MAJOR}

.if defined(DISPLAY)
post-build:	test
.else
post-build:
	#
	# DISPLAY is not set, so post-build testing is impossible
	#
.endif

test:
	cd ${WRKSRC} && ${SETENV} ITK_LIBRARY=${WRKSRC}/library \
		${WISH} tests/all.tcl -load "load ./${ITK_LIB}; package require Tk"

.include <bsd.port.mk>
