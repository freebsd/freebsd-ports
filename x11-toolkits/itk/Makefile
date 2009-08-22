# New ports collection makefile for:	itk
# Date created:		Aug 17 1996
# Whom:			chuckr
#
# $FreeBSD$
#

PORTNAME=	itk
PORTVERSION=	3.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/incrtcl/%5BIncr%20Tcl_Tk%5D-source/${PORTVERSION}-RC
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	erik@smluc.org
COMMENT=	Object-oriented extension to Tk [incr Tk]

LIB_DEPENDS=	itcl.${MAJOR}:${PORTSDIR}/lang/itcl

USE_TK=		84
USE_LDCONFIG=	yes
MAKE_ENV+=	${PLIST_SUB} \
		SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR} \
		USE_TK=${USE_TK} TCL_INCLUDEDIR=${TCL_INCLUDEDIR} \
		TK_INCLUDEDIR=${TK_INCLUDEDIR}

MAKEFILE=	${FILESDIR}/Makefile.lib
SHLIB_MAJOR=	${MAJOR}
SHLIB_MINOR=	${MINOR}
MAJOR=		${PORTVERSION:R}
MINOR=		${PORTVERSION:E}
PLIST_SUB+=	MAJOR=${MAJOR} MINOR=${MINOR}
ITK_LIB=	libitk.so.${MAJOR}
.if defined(MAKE_JOBS)
MAKE_ARGS+=	-j${MAKE_JOBS}
.endif

MANN=		Archetype.n Toplevel.n Widget.n itk.n itkvars.n usual.n

ITK_LIB_FILE=	${ITK_LIB}.${SHLIB_MAJOR}

post-build:
	#
	# Consider running ``make test'' now, if the X11 environment
	# is available in this session
	#

test:
	cd ${WRKSRC} && ${SETENV} ITK_LIBRARY=${WRKSRC}/library \
		${WISH} tests/all.tcl -load "load ./${ITK_LIB}; package require Tk"

.include <bsd.port.mk>
