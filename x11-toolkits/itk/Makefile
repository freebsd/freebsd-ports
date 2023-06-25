PORTNAME=	itk
PORTVERSION=	3.4.2
PORTREVISION=	0
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/incrtcl/%5BIncr%20Tcl_Tk%5D-source/Itk%20${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Object-oriented extension to Tk [incr Tk]
WWW=		https://sourceforge.net/projects/incrtcl/

LIB_DEPENDS=	libitcl.so.${MAJOR}:lang/itcl

USES=		tk:85,86 uidfix
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}
MAKE_ENV+=	${PLIST_SUB} \
		SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR} \
		TK_SHLIB_VER=${TK_SHLIB_VER} TCL_INCLUDEDIR=${TCL_INCLUDEDIR} \
		TK_INCLUDEDIR=${TK_INCLUDEDIR}

MAKEFILE=	${FILESDIR}/Makefile.lib
SHLIB_MAJOR=	${MAJOR}
SHLIB_MINOR=	${MINOR}
MAJOR=		${PORTVERSION:R:R}
MINOR=		${PORTVERSION:R:E}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}
ITK_LIB=	libitk.so.${MAJOR}

ITK_LIB_FILE=	${ITK_LIB}.${SHLIB_MAJOR}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

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
