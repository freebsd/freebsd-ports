# New ports collection makefile for:	mga_hal
# Date created:				12 Jan 2005
# Whom:					anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mga_hal
PORTVERSION=	4.1
CATEGORIES=	x11-servers
MASTER_SITES=	ftp://ftp.matrox.com/pub/mga/archive/linux/2004/
DISTNAME=	mgadriver-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Module for additional features with X.Org/XFree86 Matrox driver

NO_PACKAGE=	"Matrox drivers may not be distributed"
RESTRICTED=	"Matrox drivers may not be distributed."

ONLY_FOR_ARCHS= i386

PREFIX?=	${X11BASE}
WRKSRC=		${WRKDIR}/mgadriver-${PORTVERSION}
NO_BUILD=	YES

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/readme.txt ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/xfree86/6.8.1/mga_hal_drv.o \
		${PREFIX}/lib/modules/drivers/

.include <bsd.port.mk>
