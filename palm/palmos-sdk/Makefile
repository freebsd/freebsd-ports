# New ports collection makefile for:	Palm OS SDK
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palmos-sdk
PORTVERSION=	3.5
CATEGORIES=	palm
MASTER_SITES=	
DISTNAME=	sdk35

MAINTAINER=	kuriyama@FreeBSD.org

RESTRICTED=	License agreement is required.
WRKSRC=		${WRKDIR}/Palm\ OS\ 3.5\ Support
NO_BUILD=	YES

INCDIR=		${PREFIX}/palmdev/sdk-3.5/include
LIBDIR=		${PREFIX}/palmdev/sdk-3.5/lib

do-install:
	${MKDIR} ${INCDIR} ${LIBDIR}
	${CP} -Rp ${WRKSRC}/Incs/* ${INCDIR}
	${CP} -Rp ${WRKSRC}/GCC\ Libraries/* ${LIBDIR}
	${CHOWN} -R root.wheel ${INCDIR} ${LIBDIR}

.include <bsd.port.mk>
