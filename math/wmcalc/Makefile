# New ports collection makefile for:	wmcalc
# Date created:				28 March 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmcalc
PORTVERSION=	0.1
CATEGORIES=	math windowmaker
MASTER_SITES=	http://members.access1.net/ehflora/wmcalc/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

ALL_TARGET=	clean wmcalc
USE_X_PREFIX=   yes
WRKSRC=		${WRKDIR}/wmcalc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcalc ${PREFIX}/bin

.include <bsd.port.mk>
