# New ports collection makefile for:	mpexpr
# Date created:		20 April 2001
# Whom:			Chuck Hein <geekdude@pacbell.net>
#
# $FreeBSD$
#

PORTNAME=	mpexpr
PORTVERSION=	1.1
CATEGORIES=	math tcl
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple precision math for Tcl

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
USE_TCL=	84
USE_TCL_BUILD=	84
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_LDCONFIG=	yes

PLIST_DIRS=	lib/Mpexpr10
PLIST_FILES=	lib/libMpexpr10.so \
		lib/Mpexpr10/pkgIndex.tcl
MANN=		mpexpr.n

do-install:
	${MKDIR} ${PREFIX}/lib/Mpexpr10
	${INSTALL_PROGRAM} ${WRKSRC}/libMpexpr10.so ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/Mpexpr10/
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/doc/mpexpr.man ${PREFIX}/man/mann/mpexpr.n

.include <bsd.port.mk>
