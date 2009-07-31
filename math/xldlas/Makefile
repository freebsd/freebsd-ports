# New ports collection makefile for:	xldlas
# Date created:         20 Dec 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	xldlas
PORTVERSION=	0.85
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/visualization
EXTRACT_SUFX=	-source.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XForms-based statistics package

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

WRKSRC=		${WRKDIR}/xldlas

MAN1=	xldlas.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${PREFIX}/man/man1
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/help ${DATADIR}

.include <bsd.port.mk>
